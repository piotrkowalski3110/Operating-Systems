#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int flaga = 0;

void handler(int signum) {
    flaga = 1;
}

int main(void) {
  signal(SIGUSR1, handler);

    int pid_t = getpid();
    printf("\nPID: %d\n",pid_t);

  for(;;)
  {
      if(flaga == 1)
      {
        printf("Numer albumu: 50901\n");
        flaga = 0;
      }
      
      sleep(10);
  }
  return 0;
