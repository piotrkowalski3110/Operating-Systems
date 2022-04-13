 #include <omp.h>
 #include <stdio.h>
 #include <time.h>
 #include <stdlib.h>

#define vector_size 999999

int main (void)
{
    int a=3, b=6, i=0;
    int x[vector_size];
    int y[vector_size];
    time_t begin_t, end_t;

    begin_t = time(NULL);
    #pragma omp parallel for shared(y, x, a, b) private(i)

    for (i=0; i<vector_size; i++)
    {
        x[i] = rand()%100;
    }

    for (i=0; i<vector_size; i++)
    {
        y[i] = a * x[i] + b;
    }
    end_t = time(NULL);
    printf("\nStart: %d", begin_t);
    printf("\nStop: %d", end_t);

    printf("\n\nCzas: %f.\n", difftime(end_t,begin_t ));
    printf("\n");

    return 0;
}