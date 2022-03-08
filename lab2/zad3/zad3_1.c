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
    int a=0;
    printf("Podaj PID procesu do zabicia: ");
    scanf("%d",&a);

    kill(a,2);


return 0;
}