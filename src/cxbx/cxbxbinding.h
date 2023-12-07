#include <tchar.h>
#include <Windows.h>

#define CXBX_ID_GUI_STATUS_KRNL_IS_READY 1096
#define CXBX_ID_GUI_STATUS_LLE_FLAGS 1097

extern HANDLE g_cxbxHandle;

bool CxbxrExec(HWND hwnd, const TCHAR *path, const TCHAR *xbe);

void CxbxrSignalReady();
