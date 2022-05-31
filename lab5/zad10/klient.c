#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/50901"
int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[100];
   char end_str[10];

   fd = open(FIFO_FILE, O_RDWR);
   strcpy(end_str, "50901");

   while (1) {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      end_process = strcmp(readbuf, end_str);

      if (end_process != 0)
      {
         write(fd, readbuf, strlen(readbuf));
         printf("Sent: %s\n", readbuf);
         sleep(1);
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';
         printf("Received: %s\n", readbuf);
      }
      else
      {
         write(fd, readbuf, strlen(readbuf));
         printf("Sent string: %s\n", readbuf);
         break;
      }
   }
   return 0;
}