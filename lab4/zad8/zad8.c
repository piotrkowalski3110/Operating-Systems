#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *stream;

int main(void) 
{
   for(int i=1;; i++)
   {
      stream = freopen( "zad8.txt", "a+b", stderr);

      if( stream == NULL )
      {
         fprintf( stdout, "Error opening file!\n" );
      }
      else
      {
         sleep(1);
         printf("%d. 50901\n",i);
         fprintf( stream, "%d. 50901\n",i);
      }
      fclose( stream );
   }

return 0;
}