#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid_t = getpid();
    printf("Moj PID to: %d\n", pid_t);
    for(;;){}

return 0;
}