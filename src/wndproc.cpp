#include "wndproc.h"

#include <stdio.h>

#include "inject.h"

LRESULT WINAPI MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg) {
  case WM_CLOSE:
    PostMessage(NULL, WM_QUIT, wParam, lParam);
    return 0;
  case WM_PARENTNOTIFY:
    switch(LOWORD(wParam)) {
    case WM_DESTROY:
      PostMessage(NULL, WM_QUIT, wParam, lParam);
      return 0;
    case WM_COMMAND:
      switch (HIWORD(wParam)) {
      case 1096:
        MessageBoxA(0, "Set GUI is ready...", 0, 0);
        return 0;
      case 1097:
        // We don't actually handle this message, but once we get it, we know
        // the XBE has been mapped into memory, so we take the opportunity to
        // inject our own code.
        Inject();
        return 0;
      }
      break;
    }
    break;
  
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}