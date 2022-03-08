#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void term(int signum)
{
    printf("\nNumer albumu: 50901\n");
    exit(1);
}

int main()
{
    signal(SIGTERM,term);
    int pid_t = getpid();
    printf("\nPID: %d\n",pid_t);
    for(;;)
    {
        printf("\nWaiting for termination...\n");
        sleep(3);
    }

return 0;
}