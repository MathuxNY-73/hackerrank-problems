#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define INF 999999999

void findPairs(int, int[]);
int compareInt(const void*, const void*);

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    findPairs(n, ar);
    puts("");

    return 0;
}

void findPairs(int ar_size, int ar[])
{
    qsort(ar, ar_size, sizeof(int), compareInt);

    int smallestDiff = INF;
    for(int i = 0; i < ar_size - 1 ; ++i)
    {
        int diff = ar[i+1] - ar[i];
        if(diff < smallestDiff)
        {
            smallestDiff = diff;
        }
    }

    for(int i = 0; i < ar_size - 1 ; ++i)
    {
        int diff = ar[i+1] - ar[i];
        if(diff == smallestDiff)
        {
            printf("%d ", ar[i]);
            printf("%d ", ar[i+1]);
        }
    }
}

int compareInt( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}
