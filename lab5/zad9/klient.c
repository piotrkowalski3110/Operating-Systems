#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "fifo_oneway"

int fd;
char send[20];

int main() 
{
   mknod(FIFO_FILE, __S_IFIFO|0640, 0);

   for(;;)
   {
      fd = open(FIFO_FILE, O_WRONLY);
      printf("Message for server: ");
      fgets(send, 20, stdin);
      write(fd, send, strlen(send)+1);
      close(fd);
   }
   return 0;
}