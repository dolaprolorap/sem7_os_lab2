#include <stdio.h>
#include "lib.h"

int main() 
{
    char *args_1[] = {"3"};
    char *args_2[] = {"5"};
    char *args_3[] = {"8"};

    fork_command("counter", args_1, 1);
    fork_command("counter", args_2, 1);

    int pid = fork_command("counter", args_3, 1);

    wait_process(pid);
}
