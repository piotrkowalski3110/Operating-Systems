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

void reverse_string(char *);

int main(int argc, char *argv[]) {
   int shmid;
   char *bufptr;
   int spaceavailable;
   struct shmseg *shmp;
   shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
   shmp = shmat(shmid, NULL, 0);

   while (shmp->complete != 1)
   {
      bufptr = shmp->buf;
      spaceavailable = BUF_SIZE;
      
      if(strlen(shmp->buf)>0)
      {
      printf("segment contains : %s", shmp->buf);
      printf("Reading Process: Shared Memory: Read %d bytes\n\n", shmp->cnt);
      }
      strcpy(bufptr, "\0");
      //bufptr[spaceavailable-1] = '\0';
      sleep(1);
   }
   printf("\nReading Process: Complete\n");
   shmdt(shmp);
   shmctl(shmid, IPC_RMID, 0);
   return 0;
}

void reverse_string(char *str) {
   int last, limit, first;
   char temp;
   last = strlen(str) - 1;
   limit = last/2;
   first = 0;
   
   while (first < last) {
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;
}