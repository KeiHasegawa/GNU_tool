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
    case ERROR_GEN_FAILURE: return puts("ERROR_GEN_FAILURE");
    case ERROR_INVALID_NAME: return puts("ERROR_INVALID_NAME");
    default: return printf("GetLastError() = %d\n", code);
    }
}

HANDLE orange;

int except_debug_handler(EXCEPTION_DEBUG_INFO* info)
{
    puts("EXCEPTION_DEBUG_EVENT");
    printf("\t");
    DWORD code = info->ExceptionRecord.ExceptionCode;
    switch (code) {
    case EXCEPTION_BREAKPOINT:
        {
            PVOID addr = info->ExceptionRecord.ExceptionAddress;
            if (addr == (PVOID)0x000000010040108D) {
                CONTEXT ctx = { 0 };
                ctx.ContextFlags = CONTEXT_FULL;
                if (!GetThreadContext(orange, &ctx))
                    print_error();
#ifdef __CYGWIN__
                printf("Eip = 0x%llx\n", ctx.Rip);
                ctx.Dr0 = 0x100408140;
                ctx.Dr6 = 0xffff0ff0;
                ctx.Dr7 = 0xd0101;
#else // __CYGWIN__
                printf("Eip = 0x%x\n", ctx.Eip);
#endif // __CYGWIN__
                if (!SetThreadContext(orange, &ctx))
                    print_error();
            }
            return printf("EXCEPTION_BREAKPOINT : 0x%p\n", addr);
        }
    default:
        return printf("unknown exception code = 0x%x\n", code);
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
        return except_debug_handler(&event->u.Exception);
    case CREATE_THREAD_DEBUG_EVENT:
        return puts("CREATE_THREAD_DEBUG_EVENT");
    case EXIT_THREAD_DEBUG_EVENT:
        return puts("EXIT_THREAD_DEBUG_EVENT");
    case EXIT_PROCESS_DEBUG_EVENT:
        return puts("EXIT_PROCESS_DEBUG_EVENT");
    case UNLOAD_DLL_DEBUG_EVENT:
        return puts("UNLOAD_DLL_DEBUG_EVENT");
    case OUTPUT_DEBUG_STRING_EVENT:
        return puts("OUTPUT_DEBUG_STRING_EVENT");
    default:
        return printf("unexpected event code %d\n", code);
    }
}

int main()
{
    char path[] = ".\\a.exe ";
    STARTUPINFOA si = { 0 };
    si.cb = sizeof si;
    PROCESS_INFORMATION pi;
    BOOL ret = CreateProcessA(NULL, path, NULL, NULL, TRUE,
			      DEBUG_ONLY_THIS_PROCESS, NULL, NULL, &si, &pi);
    if (!ret) {
        print_error();
        return 1;
    }
    printf("pi.hProcess = 0x%p, pi.hThread = 0x%p\n", pi.hProcess, pi.hThread);
    orange = pi.hThread;
    CONTEXT ctx = { 0 };
    ctx.ContextFlags = CONTEXT_FULL;
    if (!GetThreadContext(orange, &ctx)) {
        print_error();
        return 2;
    }
#ifdef __CYGWIN__
    printf("Eip = 0x%llx\n", ctx.Rip);
#else // __CYGWIN__
    printf("Eip = 0x%x\n", ctx.Eip);
#endif // __CYGWIN__

    while (1) {
        DEBUG_EVENT event;
        if (!WaitForDebugEvent(&event, INFINITE)) {
            print_error();
            return 2;
        }
        operation(&event);
        fflush(stdout);
        if (event.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
            break;
        if (!ContinueDebugEvent(event.dwProcessId, event.dwThreadId, DBG_CONTINUE)) {
            print_error();
            return 3;
        }
    }
    return 0;
}
