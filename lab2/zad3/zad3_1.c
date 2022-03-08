#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int a=0;
    printf("Podaj PID procesu do zabicia: ");
    scanf("%d",&a);

    kill(a,15);


return 0;
}