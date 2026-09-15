#include "NoCRT.h"

#define WINAPI __stdcall

//#define exet(code) ExitProcess((unsigned int)(code))
#ifdef __cplusplus
extern "C" {
#endif
    void __chkstk(void) {
    }
#ifdef __cplusplus
}
#endif

typedef void* HANDLE;
typedef void* HWND;
typedef void* HINSTANCE;
typedef void* HDC;
typedef void* HMODULE;
typedef void* LPVOID;
typedef const char* LPCSTR;
typedef char* LPSTR;
typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef long LONG;
typedef int BOOL;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef long LRESULT;
typedef unsigned short ATOM;
typedef void* HBRUSH;
typedef void* HCURSOR;
typedef void* HICON;
typedef void* HMENU;
typedef void* HGDIOBJ;
typedef unsigned int COLORREF;

__declspec(dllimport) BOOL __stdcall BitBlt(
    HDC   hdcDest,// handle context of the shit
    int   xDest, // X-coord of the left up corna
    int   yDest, // Y-coord of the left up corna
    int   width,  // width of the rect
    int   height,// height of the rect
    HDC   hdcSrc, // handle of the src shit
    int   xSrc, // X-coord of the left up corna of Src
    int   ySrc,    // Y-coord of the left up corna of Src
    DWORD rop     // operation sheesh
);

// window procedure callback type
typedef LRESULT(*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT;

typedef struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
    DWORD lPrivate;
} MSG;

typedef struct tagWNDCLASSA {
    UINT style;
    UINT ExStyle;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
} WNDCLASSA;

typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

typedef struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
} PAINTSTRUCT;

__declspec(dllimport) ATOM __stdcall RegisterClassA(const WNDCLASSA*);
__declspec(dllimport) HWND __stdcall CreateWindowExA(
    DWORD, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
__declspec(dllimport) BOOL __stdcall ShowWindow(HWND, int);
__declspec(dllimport) BOOL __stdcall UpdateWindow(HWND);
__declspec(dllimport) BOOL __stdcall GetMessageA(MSG*, HWND, UINT, UINT);
__declspec(dllimport) BOOL __stdcall TranslateMessage(const MSG*);
__declspec(dllimport) LRESULT __stdcall DispatchMessageA(const MSG*);
__declspec(dllimport) LRESULT __stdcall DefWindowProcA(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) void __stdcall PostQuitMessage(int);
__declspec(dllimport) HINSTANCE __stdcall GetModuleHandleA(LPCSTR);
__declspec(dllimport) HDC __stdcall BeginPaint(HWND, PAINTSTRUCT*);
__declspec(dllimport) BOOL __stdcall EndPaint(HWND, const PAINTSTRUCT*);
__declspec(dllimport) void* __stdcall GetStockObject(int);
__declspec(dllimport) BOOL __stdcall FillRect(HDC, const RECT*, HBRUSH);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
__declspec(dllimport) HANDLE __stdcall LoadImageA(HINSTANCE, LPCSTR, UINT, int, int, UINT);
__declspec(dllimport) HCURSOR __stdcall LoadCursorA(HINSTANCE, LPCSTR);
__declspec(dllimport) HICON __stdcall LoadIconA(HINSTANCE, LPCSTR);
//__declspec(dllimport) void __stdcall ExitProcess(UINT);
__declspec(dllimport) BOOL __stdcall InvalidateRect(HWND, const RECT*, BOOL);
__declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);
__declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
__declspec(dllimport) int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
extern void WINAPI ExitProcess(unsigned int uExitCode);
__declspec(dllimport) HDC WINAPI __stdcall GetDC(HWND hWnd);
/*__declspec(dllimport)*/extern void WINAPI __stdcall ReleaseDC(HWND hWnd, HDC hDC);


#define WS_OVERLAPPEDWINDOW 0x00CF0000
#define WS_VISIBLE 0x10000000
#define WS_OVERLAPPED 0x00000000
#define WS_CAPTION 0x00C00000
#define WS_SYSMENU 0x00080000
#define WS_THICKFRAME 0x00040000
#define WS_MINIMIZEBOX 0x00020000
#define WS_MAXIMIZEBOX 0x00010000
#define WS_POPUP 0x80000000

#define WS_EX_TOPMOST 0x00000008
#define WS_EX_LAYERED 0x00080000
#define WS_EX_TRANSPARENT 0x00000020

#define CW_USEDEFAULT 0x80000000
#define SW_SHOW 5
#define WM_DESTROY 0x0002
#define WM_PAINT 0x000F
#define WM_LBUTTONDOWN 0x0201
#define WM_RBUTTONDOWN 0x0204
#define WM_MOUSEMOVE 0x0200
#define WM_LBUTTONUP 0x0202
#define WM_KEYDOWN 0x0100
#define WM_CLOSE 0x0010
#define WM_ERASEBKGND 0x0014

#define CS_HREDRAW 0x0002
#define CS_VREDRAW 0x0001
#define CS_OWNDC 0x0020
#define CS_DBLCLKS 0x0008

#define IDC_ARROW 32512
#define IDI_APPLICATION 32512
#define WHITE_BRUSH 0
#define DEFAULT_GUI_FONT 17

#define VK_ESCAPE 0x1B
#define VK_RETURN 0x0D
#define VK_SPACE 0x20

#define COLOR_WINDOW 5
#define COLOR_WINDOWTEXT 8
#define COLOR_BTNFACE 15

#define GRAY_BRUSH 2

#define SM_CYSCREEN 1
#define SM_CXSCREEN 0

#define SRCINVERT (unsigned long)0x00660046

#define IMAGE_CURSOR 2
#define IMAGE_ICON 1
#define LR_DEFAULTSIZE 0x00000040

#define PM_REMOVE 0x0001
#define PM_NOREMOVE 0x0000

#define MB_OK               0x00000000L
#define MB_ICONINFORMATION  0x00000040L

#ifndef NULL
#define NULL ((void*)0)
#endif

#define msg(text, text2) MessageBoxA((HWND)0, (text), (text2), MB_OK | MB_ICONINFORMATION)

__forceinline HWND create_pure_window(const char* title, WNDPROC proc) {
    HINSTANCE hInst = (HINSTANCE)GetModuleHandleA(NULL);
    WNDCLASSA wc = { 0 };
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = proc;
    wc.hInstance = hInst;
    wc.hCursor = (HCURSOR)LoadCursorA(NULL, (LPCSTR)32512); // IDC_ARROW
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszClassName = title;

    RegisterClassA(&wc);

    return CreateWindowExA(0, title, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInst, NULL);
}

#define MAKEINTRESOURCEA(i) ((LPCSTR)((unsigned long)((WORD)(i)))) \

/*
or
#define MAKEINTRESOURCEA(i) ((LPCSTR)((void*)(unsigned long_long)(i)))
*/
