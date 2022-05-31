#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "/tmp/50901"
void reverse_string(char *);

int main() {
   int fd;
   char readbuf[100];
   char end[10];
   int to_end;
   int read_bytes;

   mkfifo(FIFO_FILE, __S_IFIFO|0640);
   strcpy(end, "50901");
   fd = open(FIFO_FILE, O_RDWR);

   while(1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("Received: %s\n", readbuf);
      to_end = strcmp(readbuf, end);

      if (to_end == 0) {
         close(fd);
         remove("/tmp/50901");
         break;
      }

      reverse_string(readbuf);
      printf("Sending Reversed String: %s\n", readbuf);
      write(fd, readbuf, strlen(readbuf));
      sleep(1);
   }
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