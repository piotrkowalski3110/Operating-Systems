#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define BUF_SIZE 1024
#define SHM_KEY 0x1234

struct shmseg {
   int cnt;
   int complete;
   char buf[BUF_SIZE];
};

int main(int argc, char *argv[]) {

   char *message = NULL;
   size_t len = 0;
   int filled_count;

   int shmid;
   struct shmseg *shmp;
   char *bufptr;
   int spaceavailable;
   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   shmp = shmat(shmid, NULL, 0);
   bufptr = shmp->buf;
   spaceavailable = BUF_SIZE;

   while((getline(&message, &len, stdin)) != -1)
   {
      strcpy(bufptr, message);
      bufptr[spaceavailable-1] = '\0';
      shmp->cnt = strlen(bufptr);
      shmp->complete = 0;

      printf("Wrote %d bytes\n\n", shmp->cnt);
   }
   shmp->complete = 1;
   free(message);
   shmdt(shmp);
   return 0;
}