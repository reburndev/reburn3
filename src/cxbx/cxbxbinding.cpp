#include "cxbxbinding.h"

#include <stdio.h>

HANDLE g_cxbxHandle = NULL;

bool CxbxrExec(HWND hwnd, const TCHAR *path)
{
  STARTUPINFO startupInfo = { 0 };
  PROCESS_INFORMATION processInfo = { 0 };

  TCHAR buf[MAX_PATH];

  const TCHAR *cxbx_path = TEXT("C:\\Users\\matt\\src\\Cxbx-Reloaded\\bulid\\bin\\Release\\cxbxr-ldr.exe");
  // const TCHAR *cxbx_path = TEXT("C:\\Users\\matt\\Downloads\\CxbxReloaded-Release-VS2022\\cxbxr-ldr.exe");

  // if (_sntprintf_s(buf, MAX_PATH, TEXT("%s /load %s"), cxbx_path, path) >= MAX_PATH) {
  if (_sntprintf_s(buf, MAX_PATH, TEXT("%s /load %s /hwnd %zu"), cxbx_path, path, (size_t) hwnd) >= MAX_PATH) {
    return false;
  }

  if (CreateProcess(nullptr, buf, nullptr, nullptr, false, DETACHED_PROCESS, nullptr, nullptr, &startupInfo, &processInfo) == 0) {
    TCHAR err[256];
    _stprintf_s(err, 256, TEXT("Failed to open loader executable: %x"), GetLastError());
    MessageBox(hwnd, err, 0, 0);
    return false;
  }

  CloseHandle(processInfo.hThread);
  //CloseHandle(processInfo.hProcess);

  g_cxbxHandle = processInfo.hProcess;

  return true;
}