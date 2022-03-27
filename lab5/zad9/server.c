#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "fifo_oneway"

int fd;
char receive[20];

int main()
{

   mknod(FIFO_FILE, __S_IFIFO|0640, 0);

   for(;;)
   {
      fd = open(FIFO_FILE,O_RDONLY);
      read(fd, receive, 20);
      printf("Message from klient: %s", receive);
      close(fd);
   }
    return 0;
}
