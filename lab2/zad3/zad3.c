#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void handler(int sig)
{
    printf("\nNumer albumu: 50901\n");
    exit(1);
}

int main()
{
    int pid_t = getpid();
    int x = 0;
    printf("Pid: %d\n", pid_t);

    signal(SIGINT, handler);
        for(;;)
        {
            printf("Waiting for signal...\n");
            sleep(3);
        }

    return 0;
}