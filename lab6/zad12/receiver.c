#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int main(void) {
   struct my_msgbuf buf;
   int msqid;
   int toend;
   int len;
   int mode = 1;
   key_t key;

   if ((key = ftok("50901.txt", 'B')) == -1)
   {
      perror("ftok error");
      exit(1);
   }

   if ((msqid = msgget(key, PERMS)) == -1)
   {
      perror("Can't connect to queue!");
      exit(1);
   }

   while(1)
   {
       if(mode == 0)
       {
        printf("Send: ");
        fgets(buf.mtext, sizeof buf.mtext, stdin);
        len = strlen(buf.mtext);
        if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
        if (msgsnd(msqid, &buf, len+1, 0) == -1)  perror("Sending error!");
        toend = strcmp(buf.mtext,"50901");
        if (toend == 0)   break;
        mode = 1;
       }

       if(mode == 1)
       {
            if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1)
            {
                perror("Can't receive message!");
                exit(1);
            }

            printf("Received: \"%s\"\n", buf.mtext);
            toend = strcmp(buf.mtext,"50901");
            if (toend == 0)   break;
            mode = 0;
       }
   }

   
   printf("Ending receiving messages...\n");
   system("rm 50901.txt");
   return 0;
}