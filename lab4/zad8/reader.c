#include <stdio.h>
#include <unistd.h>

FILE *stream;
char line[256];

int main( void )
{
   stream = freopen( "zad8.txt", "r", stdin);

   if( stream == NULL )
   {
      printf("Error opening file! Does not exist or no permission!\n" );
   }

   else
   {
      for(;;)
      {
         while(fgets(line,256,stdin))
         {
            puts(line);
         }
         clearerr(stdin);
         sleep(1);
      }
   }

   return 0;
}