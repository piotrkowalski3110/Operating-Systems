#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

bool flaga;

void sigusr1_handler(int signum) {
    flaga = true;
}

int main(void) {
  signal(SIGUSR1, sigusr1_handler);

    int pid_t = getpid();
    printf("\nPID: %d\n",pid_t);

  for(;;)
  {
      if(flaga == true)
      {
        printf("Numer albumu: 50901\n");
        flaga = false;
      }
      
      sleep(10);
  }
  return 0;
}