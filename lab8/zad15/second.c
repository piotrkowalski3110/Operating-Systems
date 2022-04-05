#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x12345

struct shmseg {
   int cntr;
   int write_complete;
   int read_complete;
   char buf[BUF_SIZE];
};

int main(void) {
   int shmid, numtimes;
   struct shmseg *shmp;
   int total_count;
   int cntr;
   int sleep_time;

   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   while (shmp->write_complete != 1) {
      if (shmp->cntr == -1) {
         perror("read");
         return 1;
      }
      sleep(3);
   }
   printf("Reading Process: %d\n", shmp->cntr);
   shmp->read_complete = 1;

   if (shmdt(shmp) == -1) {
      perror("shmdt");
      return 1;
   }
   printf("Reading Process: Complete\n");
   return 0;
}