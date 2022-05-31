#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "50901"

   int stream;
   char receive[80];
   char end[10];
   int status;
   int len;

int main() {

   mknod(FIFO_FILE, __S_IFIFO|0640, 0);
   strcpy(end, "50901");
   stream = open(FIFO_FILE, O_RDONLY);

   for(;;){
      len = read(stream, receive, sizeof(receive));
      receive[len] = '\0';
      printf("Message from client: %s\n", receive);

      status = strcmp(receive, end);
      if (status == 0) {
         close(stream);
         printf("\nENDING...\n");
         break;
      }
   }
   return 0;
}