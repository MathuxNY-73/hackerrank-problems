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

int dichotomique_mod_pow(int a, int p, int mod) {
    if(a == 0) {
        return 0;
    }
    if(p == 0) {
        return 1;
    }

    long res = 0;
    if (p % 2 == 0) {
        res = dichotomique_mod_pow(a, p / 2, mod);
        res = (res * res) % mod;
    }
    else {
        res = dichotomique_mod_pow(a, p-1, mod);
        res = (a * res) % mod;
    }
    return (int)((res + mod) % mod);
}

int solve(int n, int m) {
    int base = pow(10,9) + 7;
    long int res = 1;

    for(int i = n+m-1 ; i > max(n,m-1) ; --i) {
        res = ((res % base) * (i % base)) % base;
    }

    long int res_k = 1;
    for(int i = min(n,m-1) ; i > 0 ; --i) {
        res_k = (res_k * i) % base;
    }

    int p = base - 2;
    long int x = res_k;
    long int res_pow_k = 1;
    while(p > 0) {
        if (p & 1) {
            res_pow_k = (res_pow_k * x) % base;
        }
        p >>= 1;
        x = (x * x) % base;
    }

    res = ((res % base) * res_pow_k) % base;

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
        int n = 0, m = 0;
        fastscan_int(&n);
        fastscan_int(&m);

        int result = solve(n, m);

        printf("%d\n", result);
    }

    return 0;
}
