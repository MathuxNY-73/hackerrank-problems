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
int* solve(int n, int* result_count) {
    *result_count = n+1;

    int** res = malloc(sizeof(int*) * (n+1));
    res[0] = malloc(sizeof(int));
    res[0][0] = 1;

    for(int i = 1; i <= n ; ++i)
    {
        res[i] = malloc(sizeof(int) * (i + 1));
        for(int j = 0 ; j <= i ; ++j)
        {
            int r = j > 0 ? res[i-1][j-1] : 0;
            int l = j < i ? res[i-1][j] : 0;
            res[i][j] = (r + l) % 1000000000;
        }
        free(res[i-1]);
    }

    int* tmp = res[n];
    free(res);
    return tmp;
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
    int t = 0;
    fastscan_int(&t);

    wl(t)
    {
        int n =0;
        fastscan_int(&n);

        int result_count = 0;

        int* result = solve(n, &result_count);

        for(int i = 0 ; i < result_count ; ++i)
        {
            printf("%d ", result[i]);
        }

        printf("\n");

        free(result);
    }

    return 0;
}
