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
#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
        __typeof__ (b) _b = (b); \
        _a > _b ? _a : _b; })
#define min(a,b)                                \
    ({ __typeof__ (a) _a = (a);                 \
        __typeof__ (b) _b = (b);                \
        _a < _b ? _a : _b; })
#define fl(i,a,b) for(i=a; i<b; ++i)

int fibonacci_memoized(int n, int* memo) {

    if(n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    };

    if(memo[n] == -1) {
        memo[n] = fibonacci_memoized(n-1, memo) + fibonacci_memoized(n-2, memo);
    }
    return memo[n];
}

int fibonacci(int n) {

    size_t memo_s = sizeof(int) * (n+1);
    int* memo = malloc(memo_s);
    memset(memo, -1, memo_s);

    int res = fibonacci_memoized(n, memo);

    free(memo);
    return res;
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
        int n = 0;
        fastscan_int(&n);

        int result = fibonacci(n);

        printf("%d\n", result);
    }

    return 0;
}
