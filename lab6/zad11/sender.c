#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int main(void) {
   struct my_msgbuf buf;
   int msqid;
   int len;
   int toend;

   key_t key;
   system("touch 50901.txt");

   if ((key = ftok("50901.txt", 'B')) == -1) {
        perror("ftok error");
        exit(1);
   }

   if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1)
   {
        perror("Can't receive message!");
        exit(1);
   }

   printf("Send: (50901 to end)\n");
   buf.mtype = 1;

   while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL)
   {
        len = strlen(buf.mtext);
        if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
        if (msgsnd(msqid, &buf, len+1, 0) == -1)  perror("Sending error!");
        toend = strcmp(buf.mtext,"50901");
        if (toend == 0)   break;
   }

   strcpy(buf.mtext, "50901");
   len = strlen(buf.mtext);
   if (msgsnd(msqid, &buf, len+1, 0) == -1) perror("Sending error!");

   if (msgctl(msqid, IPC_RMID, NULL) == -1)
   {
        perror("Can't control queue!");
        exit(1);
   }

   printf("Stop sending messages...\n");
   return 0;
}