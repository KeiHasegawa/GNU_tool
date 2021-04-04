#include <processthreadsapi.h>
#include <errhandlingapi.h>
#include <winerror.h>
#define HWND void*
#include <WinBase.h>
#include <debugapi.h>
#include <minwinbase.h>
#include <stdio.h>
#include <assert.h>

int print_error()
{
    DWORD code = GetLastError();
    switch (code) {
    case NO_ERROR: return puts("NO_ERROR");
    case ERROR_INVALID_FUNCTION: return puts("ERROR_INVALID_FUNCTION");
    case ERROR_INVALID_HANDLE: return puts("ERROR_INVALID_HANDLE");
    default:
        return printf("GetLastError() = 0x%x\n", code);
    }
}

int except_handler(DEBUG_EVENT* event)
{
    assert(event->dwDebugEventCode == EXCEPTION_DEBUG_EVENT);
    DWORD code = event->u.Exception.ExceptionRecord.ExceptionCode;
    switch (code) {
    case EXCEPTION_BREAKPOINT:
        return puts("EXCEPTION_BREAKPOINT");
    default:
        return printf("unknown exception code = %d\n", code);
    }
}

int operation(DEBUG_EVENT* event)
{
    DWORD code = event->dwDebugEventCode;
    switch (code) {
    case CREATE_PROCESS_DEBUG_EVENT:
        return puts("CREATE_PROCESS_DEBUG_EVENT");
    case LOAD_DLL_DEBUG_EVENT:
        return puts("LOAD_DLL_DEBUG_EVENT");
    case EXCEPTION_DEBUG_EVENT:
        puts("EXCEPTION_DEBUG_EVENT");
        return except_handler(event);
    case CREATE_THREAD_DEBUG_EVENT:
        return puts("CREATE_THREAD_DEBUG_EVENT");
    case EXIT_THREAD_DEBUG_EVENT:
        return puts("EXIT_THREAD_DEBUG_EVENT");
    case EXIT_PROCESS_DEBUG_EVENT:
        return puts("EXIT_PROCESS_DEBUG_EVENT");
    case UNLOAD_DLL_DEBUG_EVENT:
        return puts("UNLOAD_DLL_DEBUG_EVENT");
    default:
        return printf("unexpected event code %d\n", code);
    }
}

int main()
{
    char path[] = "..\\test000\\x64\\Debug\\test000.exe";
    STARTUPINFOA si = { 0 };
    si.cb = sizeof si;
    PROCESS_INFORMATION pi;
    BOOL ret = CreateProcessA(NULL, path,
        NULL, NULL, FALSE, DEBUG_ONLY_THIS_PROCESS, NULL, ".", &si, &pi);
    if (!ret) {
        print_error();
        return 1;
    }

    while (1) {
        DEBUG_EVENT event;
        if (!WaitForDebugEvent(&event, INFINITE)) {
            print_error();
            return 2;
        }
        operation(&event);
        if (event.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
            break;
        if (!ContinueDebugEvent(event.dwProcessId, event.dwThreadId, DBG_CONTINUE)) {
            print_error();
            return 3;
        }
    }
    return 0;
}
