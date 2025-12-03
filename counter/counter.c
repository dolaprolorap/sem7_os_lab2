#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void crossplatform_sleep(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

int main(int argc, char *argv[]) 
{
    int tick_count = atoi(argv[1]);

    printf("PID %d начинает считать...\n", getpid());

    for (int i = 0; i < tick_count; i++)
    {
        crossplatform_sleep(1);

        printf("PID %d отсчитал %d\n", getpid(), i);
    }

    printf("PID %d расчет окончил!\n", getpid());

    return 0;
}
