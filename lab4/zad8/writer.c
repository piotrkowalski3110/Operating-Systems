#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *stream;

int main(void)
{
   stream = freopen( "zad8.txt", "a+b", stdout);

   for(int i=1;; i++)
   {
      printf("%d. 50901\n",i);
      fflush(stdout);
      sleep(1);
   }
   return 0;
}