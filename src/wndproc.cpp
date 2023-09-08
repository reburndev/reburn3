#include "wndproc.h"

#include <shlwapi.h>
#include <stdio.h>

#include "cxbx/cxbxbinding.h"
#include "inject.h"

HWND childHwnd = NULL;

LRESULT WINAPI MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg) {
  case WM_CLOSE:
    PostMessage(NULL, WM_QUIT, wParam, lParam);
    return 0;
  case WM_PARENTNOTIFY:
    switch(LOWORD(wParam)) {
    case WM_CREATE:
      childHwnd = GetWindow(hWnd, GW_CHILD);
      return 0;
    case WM_DESTROY:
      PostMessage(NULL, WM_QUIT, wParam, lParam);
      return 0;
    case WM_COMMAND:
      switch (HIWORD(wParam)) {
      case CXBX_ID_GUI_STATUS_KRNL_IS_READY:
        // Cxbx expects a signal from the GUI after sending this message
        CxbxrSignalReady();
        break;
      case CXBX_ID_GUI_STATUS_LLE_FLAGS:
        // We don't actually handle this message, but once we get it, we know
        // the XBE has been mapped into memory, so we take the opportunity to
        // inject our own code.
        TCHAR dllName[MAX_PATH];
        GetModuleFileName(GetModuleHandle(nullptr), dllName, MAX_PATH);
        PathRemoveFileSpec(dllName);
        PathAppend(dllName, TEXT("\\reburn3inject.dll"));

        size_t dllNameSz = (wcslen(dllName) + 1) * sizeof(wchar_t);
        LPVOID loadLibraryFunc = (LPVOID) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "LoadLibraryW");
        LPVOID remoteMem = VirtualAllocEx(g_cxbxHandle, NULL, dllNameSz, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
        WriteProcessMemory(g_cxbxHandle, remoteMem, dllName, dllNameSz, NULL);

        HANDLE remoteThread = CreateRemoteThread(g_cxbxHandle, NULL, 0, (LPTHREAD_START_ROUTINE) loadLibraryFunc, remoteMem, NULL, NULL);
        CloseHandle(remoteThread);
        return 0;
      }
      break;
    }
    break;
  case WM_SIZE:
  {
    if (childHwnd) {
      // Keep at 4:3 aspect ratio (Burnout 3 actually supports 16:9, but I
      // don't know how to activate this yet)
      const float target_ar = 4.0f / 3.0f;

      int w = LOWORD(lParam);
      int h = HIWORD(lParam);
      int x = 0;
      int y = 0;

      /*float our_ar = float(w) / float(h);
      if (our_ar > target_ar) {
        // Window is wider, scale by height
        int tw = int(h * target_ar);
        x = w / 2 - tw / 2;
        w = tw;
      } else {
        // Window is taller, scale by width
        int th = int(w / target_ar);
        y = h / 2 - th / 2;
        h = th;
      }*/

      MoveWindow(childHwnd, x, y, w, h, FALSE);
    }
    break;
  }
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
