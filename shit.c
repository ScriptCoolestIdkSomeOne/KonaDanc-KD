#define _FILE_STAT_INFORMATION_
/*#define _FILE_STAT_LX_INFORMATION_
#define _FILE_CASE_SENSITIVE_INFORMATION_
//#define __FILE_STAT_INFORMATION_DEFINED__
#define __FILE_STAT_LX_INFORMATION_DEFINED__
//#define __FILE_CASE_SENSITIVE_INFORMATION_DEFINED__
//#define _FILE_CASE_SENSITIVE_INFORMATION_
*/#define _FILE_STAT_LX_INFORMATION_
//#include "additionalshit.h"
#include "Mint\Mint.h"
#include "ASNT.h"
#include "Mint/Mint.Implementation/ntpsapi.h"
#pragma check_stack(off)

LRESULT __stdcall WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        EndPaint(hwnd, &ps);
        return 0;
    }
    }
    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

void shit() {
    pfnNtTerminateProcess myNtTerminate = ntshit();
    HWND hwnd = create_pure_window("my shit", WindowProc);

    if (!hwnd) {
        exet(1);
    }

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    exet(0);
}
