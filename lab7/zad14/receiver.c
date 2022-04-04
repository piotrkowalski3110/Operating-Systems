#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <signal.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234
int flag;

struct shmseg {
   int cnt;
   int complete;
   char buf[BUF_SIZE];
};

void sig_handler(int signum)
{
    flag = 1;
}

int main(int argc, char *argv[]) {
   int shmid;
   char *bufptr;
   int spaceavailable;
   struct shmseg *shmp;
   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   shmp = shmat(shmid, NULL, 0);
   signal(SIGUSR1, sig_handler);

    int pid_t = getpid();
    printf("Moj PID to: %d\n", pid_t);

   while (shmp->complete != 1)
   {
      if(flag == 1)
      {
      printf("segment contains : %s", shmp->buf);
      printf("Reading Process: Shared Memory: Read %d bytes\n\n", shmp->cnt);
      }
      flag = 0;
      sleep(1);
   }
   printf("\nReading Process: Complete\n");
   shmdt(shmp);
   shmctl(shmid, IPC_RMID, 0);
   return 0;
}