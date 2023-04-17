#include <stdio.h>
#include <TCHAR.H>
#include <Windows.h>

#include "cxbx/cxbxbinding.h"
#include "memory.h"
#include "res/resource.h"
#include "wndproc.h"

int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
)
{
  /*if (MEMORY_BUFFER != (LPVOID) 0x11000) {
    MessageBox(0, TEXT("Memory buffer has been compiled to the wrong offset."), 0, 0);
    return 0;
  }*/

  TCHAR xbePath[MAX_PATH];
  TCHAR cxbxPath[MAX_PATH];

  xbePath[0] = 0;
  cxbxPath[0] = 0;

  OPENFILENAME ofn;
  ZeroMemory(&ofn, sizeof(ofn));
  ofn.lStructSize = sizeof(ofn);
  ofn.lpstrFilter = TEXT("default.xbe\0default.xbe\0");
  ofn.lpstrFile = xbePath;
  ofn.nMaxFile = MAX_PATH;
  ofn.lpstrTitle = TEXT("Where is Burnout 3 located?");

  if (!GetOpenFileName(&ofn)) {
    return 0;
  }

  ofn.lpstrFilter = TEXT("cxbxr-ldr.exe\0cxbxr-ldr.exe\0");
  ofn.lpstrFile = cxbxPath;
  ofn.lpstrTitle = TEXT("Where is Cxbx located?");

  if (!GetOpenFileName(&ofn)) {
    return 0;
  }

  const TCHAR *CLASS_NAME = TEXT("mainWnd");

  WNDCLASS wndclass;
  ZeroMemory(&wndclass, sizeof(WNDCLASS));
  wndclass.hInstance = hInstance;
  wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
  wndclass.lpszClassName = CLASS_NAME;
  wndclass.lpfnWndProc = MainWndProc;
  wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
  RegisterClass(&wndclass);

  DWORD dwStyle = WS_OVERLAPPEDWINDOW;

  const bool isWindowed = true;
  if (!isWindowed) {
    dwStyle = WS_POPUP;
    nShowCmd = SW_SHOWMAXIMIZED;
  }

  RECT wndrect = {0, 0, 640, 480};
  AdjustWindowRect(&wndrect, dwStyle, false);

  HWND wnd = CreateWindow(CLASS_NAME, TEXT("Reburn 3: Takedown"), dwStyle,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          wndrect.right - wndrect.left, wndrect.bottom - wndrect.top,
                          NULL, NULL, hInstance, NULL);
  if (wnd == NULL) {
    MessageBox(0, TEXT("Failed to create window"), 0, 0);
    return 0;
  }

  ShowWindow(wnd, nShowCmd);

  if (!CxbxrExec(wnd, cxbxPath, xbePath)) {
    return 0;
  }

  MSG msg;
  bool quit = false;
  while (!quit) {
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) {
        quit = true;
        break;
      }

      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    WaitMessage();
  }

  DestroyWindow(wnd);

  return msg.wParam;
}
