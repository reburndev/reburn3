#include "cxbxbinding.h"

#include <stdio.h>

HANDLE g_cxbxHandle = NULL;

bool CxbxrExec(HWND hwnd, const TCHAR *cxbx, const TCHAR *xbe)
{
  STARTUPINFO startupInfo = { 0 };
  PROCESS_INFORMATION processInfo = { 0 };

  TCHAR buf[MAX_PATH];

  if (_sntprintf_s(buf, MAX_PATH, TEXT("%s /load %s /hwnd %zu"), cxbx, xbe, (size_t) hwnd) >= MAX_PATH) {
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

  return true;
}
