#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

unsigned int alarm(unsigned int seconds);

void alarmhandler(int signum)
{
    printf("Numer albumu: 50901\n");
}

int main(void)
{
  signal(SIGALRM, alarmhandler);
  alarm(3);

  for(;;)
  {

  }
  return 0;
}