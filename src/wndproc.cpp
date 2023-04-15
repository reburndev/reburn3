#include "wndproc.h"

#include <gui/resource/ResCxbx.h>
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
      case ID_GUI_STATUS_KRNL_IS_READY:
        MessageBoxA(0, "Set GUI is ready...", 0, 0);
        //g_EmuShared->SetIsReady(true);
        return 0;
      case ID_GUI_STATUS_LLE_FLAGS:
        // We don't actually handle this message, but once we get it, we know
        // the XBE has been mapped into memory, so we take the opportunity to
        // inject our own code.
        MessageBoxA(0, "inject again", 0, 0);
        //Inject();
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

      float our_ar = float(w) / float(h);
      if (our_ar > target_ar) {
        // Window is wider, scale by height
        int tw = h * target_ar;
        x = w / 2 - tw / 2;
        w = tw;
      } else {
        // Window is taller, scale by width
        int th = w / target_ar;
        y = h / 2 - th / 2;
        h = th;
      }

      MoveWindow(childHwnd, x, y, w, h, FALSE);
    }
    break;
  }
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}