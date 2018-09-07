#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)

// Complete the getWays function below.
long getWays(long n, int c_count, long* c) {
    long ways[n+1];

    memset(ways, 0, sizeof(ways));

    ways[0] = 1;

    for(int i = 0 ; i < c_count ; ++i)
    {
        for(long j = c[i] ; j <= n ; ++j)
        {
            ways[j] += ways[j - c[i]];
        }
    }

    return ways[n];
}

long getWays_2(long n, int c_count, long* c) {
    long ways[c_count][n+1];

    for(int i = 0 ; i < c_count ; ++i)
    {
        ways[i][0] = 1;
        memset(ways[i] + 1, 0, n * sizeof(long));
    }

    for(int i = 1 ; i <= n ; ++i)
    {
        for(long j = 0 ; j < c_count ; ++j)
        {
            ways[j][i] += i >= c[j] ? ways[j][i - c[j]] : 0;
            ways[j][i] += j > 0 ? ways[j-1][i] : 0;
        }
    }

    return ways[c_count-1][n];
}

void fastscan_long(long* number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    *number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        *number = *number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *number *= -1;
}

void fastscan_int(int* number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    *number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        *number = *number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *number *= -1;
}

int main()
{
    long n = 0;
    int m = 0;
    fastscan_long(&n);
    fastscan_int(&m);

    long* coins = malloc(sizeof(long) * m);

    int i;
    fl(i,0,m)
    {
        fastscan_long(&coins[i]);
    }

    long result = getWays_2(n, m, coins);
        printf("%ld\n", result);

    free(coins);

    return 0;
}
