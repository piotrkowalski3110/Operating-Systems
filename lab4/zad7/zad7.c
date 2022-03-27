#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

unsigned int alarm(unsigned int seconds);

void alarmhandler(int signum) 
{
    printf("Numer albumu: 50901\n");
    exit(1);
}

int main(void) 
{
  signal(SIGALRM, alarmhandler);
  alarm(3);

  for(int i=1;;i++){
 
    printf("%d. Waiting for alarm...\n",i);
    sleep(1);
  }
  return 0;
}