#include "lib.h"
#include <windows.h>
#include <stdio.h>

#define MAX_CMDLINE 2048

int fork_command(const char *command, char *const arg[], int arg_len)
{
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    char cmdline[MAX_CMDLINE] = {0};
    strcat(cmdline, command);
    strcat(cmdline, " ");

    for (int i = 1; arg[i] != NULL; i++) {
        strcat(cmdline, arg[i]);
        strcat(cmdline, " ");
    }

    if (!CreateProcessA(
            NULL,
            cmdline,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        perror("Ошибка выполнения: ");
        return -1;
    }

    CloseHandle(pi.hThread);

    return (int)pi.dwProcessId;
}

int wait_process(int pid)
{
    HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | SYNCHRONIZE, FALSE, pid);

    if (process == NULL) {
        perror("Ошибка выполнения: ");

        return -1;
    }

    DWORD result = WaitForSingleObject(process, INFINITE);

    if (result != WAIT_OBJECT_0) {
        perror("Ошибка выполнения: ");
        CloseHandle(process);
        return -1;
    }

    DWORD exit_code;

    if (!GetExitCodeProcess(process, &exit_code)) {
        perror("Ошибка выполнения: ");
        CloseHandle(process);
        return -1;
    }

    CloseHandle(process);

    return (int)exit_code;
}
