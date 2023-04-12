#include <stdio.h>
#include <TCHAR.H>
#include <Windows.h>

#include "memory.h"

int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
)
{
  TCHAR buf[100];
  _stprintf_s(buf, TEXT("Memory buffer located at: %p"), MEMORY_BUFFER);
  MessageBox(0, buf, 0, 0);

  const TCHAR CLASS_NAME = TEXT("mainWnd");

  WNDCLASS wndclass;
  ZeroMemory(&wndclass, sizeof(WNDCLASS));
  wndclass.hInstance = hInstance;
  wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
  wndclass.lpszClassName = CLASS_NAME;
  wndclass.lpfnWndProc = DefWindowProc;
  RegisterClass(&wndclass);

  HWND wnd = CreateWindow(CLASS_NAME, TEXT("Reburn 3: Takedown"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
  if (wnd == NULL) {
    MessageBox(0, TEXT("Failed to create window"), 0, 0);
    return 1;
  }

  ShowWindow(wnd, nShowCmd);

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

  return 0;
}
