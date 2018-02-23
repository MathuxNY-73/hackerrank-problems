#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define INF 9999999999

void giveCandies(int, int[]);
int compareInt(const void*, const void*);

int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    giveCandies(n, ar);
    puts("");

    return 0;
}

void giveCandies(int ar_size, int ar[])
{
    for(int i = 0; i < ar_size ; ++i)
    {
        
    }
}

void dfs(int v[])
{

}

int compareInt( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}
