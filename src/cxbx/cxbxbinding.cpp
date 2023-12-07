#include "cxbxbinding.h"

#include <chrono>
#include <stdio.h>

HANDLE g_cxbxHandle = NULL;
HWND g_parentWnd = NULL;
long long g_cxbxSessionID = 0;

DWORD WINAPI WaitForClose(HANDLE hProcess)
{
  WaitForSingleObject(hProcess, INFINITE);
  PostMessage(g_parentWnd, WM_QUIT, 0, 0);
  return 0;
}

bool CxbxrExec(HWND hwnd, const TCHAR *cxbx, const TCHAR *xbe)
{
  STARTUPINFO startupInfo = { 0 };
  PROCESS_INFORMATION processInfo = { 0 };

  TCHAR buf[MAX_PATH];

  g_cxbxSessionID = std::chrono::steady_clock::now().time_since_epoch().count();

  if (_sntprintf_s(buf, MAX_PATH, TEXT("\"%s\" /load \"%s\" /hwnd %zu /sid %lld"), cxbx, xbe, (size_t) hwnd, g_cxbxSessionID) >= MAX_PATH) {
    return false;
  }

  if (CreateProcess(nullptr, buf, nullptr, nullptr, false, DETACHED_PROCESS, nullptr, nullptr, &startupInfo, &processInfo) == 0) {
    TCHAR err[256];
    _stprintf_s(err, 256, TEXT("Failed to open loader executable: %x"), GetLastError());
    MessageBox(hwnd, err, 0, 0);
    return false;
  }

  CloseHandle(processInfo.hThread);

  g_cxbxHandle = processInfo.hProcess;
  g_parentWnd = hwnd;

  CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) WaitForClose, g_cxbxHandle, 0, NULL));

  return true;
}

// For some reason, cxbxr-emu requires a signal that the GUI is ready if the
// top-level window is not its own (e.g. our window). There is no DLL export to
// send that signal, meaning to do this would require importing a significant
// amount of their codebase into ours. Instead, we cheat this by accessing the
// shared memory object used to communicate with cxbxr-emu, and forcing the
// value manually. This is obviously incredibly hacky, especially because this
// value is *supposed* to be behind a mutex and we blatantly write to it with no
// protection (though Cxbx just polls this value every 100ms until it changes,
// so the actual chances of something going wrong here are virtually none).
//
// I wouldn't do this otherwise, but I really don't want to entangle a lot of
// Cxbx code in here, nor do I want to maintain a fork of Cxbx solely to remove
// the check for this signal.
void CxbxrSignalReady()
{
  const size_t readyVarOffset = 0x72;
  TCHAR emuSharedPath[256];
  _stprintf_s(emuSharedPath, 256, TEXT("Local\\EmuShared-s%lld"), g_cxbxSessionID);
  HANDLE hMapObject = CreateFileMapping
  (
      INVALID_HANDLE_VALUE,   // Paging file
      nullptr,                // default security attributes
      PAGE_READWRITE,         // read/write access
      0,                      // size: high 32 bits
      readyVarOffset + 1,     // size: low 32 bits (we only need enough to access the ready variable)
      emuSharedPath           // name of map object
  );
  if (!hMapObject) {
    return;
  }
  if (GetLastError() != ERROR_ALREADY_EXISTS) {
    return;
  }

  char *emuShared = (char*)MapViewOfFile
  (
      hMapObject,     // object to map view of
      FILE_MAP_WRITE, // read/write access
      0,              // high offset:  map from
      0,              // low offset:   beginning
      0               // default: map entire file
  );
  if (!emuShared) {
    return;
  }

  // Absolutely filthy hack mentioned above
  emuShared[readyVarOffset] = 1;

  UnmapViewOfFile(emuShared);
  CloseHandle(hMapObject);
}
