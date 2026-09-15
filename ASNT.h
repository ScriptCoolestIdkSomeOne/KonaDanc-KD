#undef exet
typedef NTSTATUS(NTAPI* pfnNtTerminateProcess)(HANDLE ProcessHandle, NTSTATUS ExitStatus);

#define exet(code) if (myNtTerminate) myNtTerminate((HANDLE)-1, (NTSTATUS)(code))


/* for some reason ifndef endif doesn't works so implement hea */
void* memset(void* dest, int c, size_t count) {
    unsigned char* p = (unsigned char*)dest;
    while (count--) {
        *p++ = (unsigned char)c;
    }
    return dest;
}

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
typedef NTSTATUS(NTAPI* pfnNtTerminateProcess)(HANDLE ProcessHandle, NTSTATUS ExitStatus);

pfnNtTerminateProcess ntshit() {
    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return NULL;

    return (pfnNtTerminateProcess)GetProcAddress(hNtdll, "NtTerminateProcess");
}
