#ifndef LIB_H
#define LIB_H

int fork_command(const char *command, char *const arg[], int arg_len);
int wait_process(int pid);

#endif // LIB_H
