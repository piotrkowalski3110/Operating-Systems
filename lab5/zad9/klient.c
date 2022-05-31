#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "50901"

   int stream;
   int status;
   int len;
   char send[20];
   char end[10];

int main() {

   stream = open(FIFO_FILE, O_WRONLY);
   strcpy(end, "50901");

   for(;;)
   {
      printf("Send message to server: ");
      fgets(send, sizeof(send), stdin);

      len = strlen(send);
      send[len - 1] = '\0';
      status = strcmp(send, end);

      if (status != 0)
      {
         write(stream, send, strlen(send));
      }

      else
      {
         write(stream, send, strlen(send));
         close(stream);
         printf("\nENDING...\n");
         break;
      }
   }
   return 0;
}