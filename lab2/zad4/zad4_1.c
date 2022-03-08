#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int pid_t;
    printf("Podaj PID procesu do zabicia: ");
    scanf("%d",&pid_t);

    kill(pid_t, SIGTERM);

return 0;
}