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

unsigned long long int* solve(int n, int k) {
    unsigned long long int* res[2];
    int base = pow(10,9);

    res[0] = malloc(sizeof(unsigned long long int) * (k+1));
    res[1] = malloc(sizeof(unsigned long long int) * (k+1));
    memset(res[0], 0, sizeof(unsigned long long int) * (k+1));
    memset(res[1], 0, sizeof(unsigned long long int) * (k+1));
    res[0][0] = 1;

    for(int i = 1 ; i < k + n ; ++i)
    {
        for(int j = 0 ; j <= k ; ++j)
        {
            unsigned long long int l = j > 0 ? res[(i-1)%2][j-1] : 0;
            unsigned long long int r = res[(i-1)%2][j];
            res[i%2][j] = fmodl(l+r, base);
        }
    }
    free(res[(k+n)%2]);
    return res[(k+n-1)%2];
}

unsigned long long int solve_dp(int n, int k) {
    int base = pow(10,9);
    unsigned long long int res[k+1][n];

    for(int i = 0 ; i < n ; ++i)
    {
        res[0][i] = 1;
    }

    for(int i = 1 ; i<k+1 ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            res[i][j] = fmodl(res[i-1][j] + (j > 0 ? res[i][j-1] : 0), base);
        }
    }

    return res[k][n-1];
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
        int n = 0, k = 0;
        fastscan_int(&n);
        fastscan_int(&k);
        /*
        unsigned long long int* result = solve(n, k);

        printf("%llu\n", result[k]);
        free(result);
        */

        unsigned long long int result = solve_dp(n, k);

        printf("%llu\n", result);
    }

    return 0;
}
