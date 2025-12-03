#include "lib.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char *const* merge(char *const arg1[], char *const arg2[], int arg1_len, int arg2_len)
{
    char **merged = malloc((arg1_len + arg2_len) * sizeof(char *const));

    for (int i = 0; i < arg1_len; i++)
    {
        merged[i] = arg1[i];
    }

    for (int i = 0; i < arg2_len; i++)
    {
        merged[arg1_len + i] = arg2[i];
    }

    return merged;
}

int fork_command(const char *command, char *const arg[], int arg_len)
{
    int pid = fork();

    if (pid != 0)
    {
        return pid;
    }

    char *const command_name[] = {command};
    char *const null_terminator[] = {NULL};

    char *const *arg_with_name = merge(command_name, arg, 1, arg_len);
    char *const *arg_with_terminator = merge(arg_with_name, null_terminator, arg_len + 1, 1);

    execvp(command, arg_with_terminator);
    perror("Ошибка выполнения (execvp)");

    _exit(1);
}

int wait_process(int pid)
{
    int status;

    if (waitpid(pid, &status, 0) < 0) {
        perror("Ошибка выполнения (watipid < 0)");

        return -1;
    }

    if (WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }

    if (WIFSIGNALED(status)) {
        return 128 + WTERMSIG(status);
    }

    return -1;
}
