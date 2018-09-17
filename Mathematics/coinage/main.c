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
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a

// Complete the getWays function below.
int solve(int n, int coins_count, int* coins) {
    int res = 0;
    int* count = malloc(sizeof(int) * (n+1));
    memset(count, 0, sizeof(int) * (n+1));
    
    for(int i = 0 ; i <= coins[1] && i*2<=n; ++i)
    {
        for(int j = 0 ; j <= coins[0] && j + i*2 <= n ; ++j)
        {
            ++count[j+2*i];
        }
    }
    for(int i = 0 ; i <= coins[3] && i*10<=n ; ++i)
    {
        for(int j = 0 ; j <= coins[2] && j*5 + i*10 <=n ; ++j)
        {
            res += count[n - i*10 - j*5];
        }   
    }

    free(count);
    return res;
}

int sub_solve(int n, int c1, int c2, int n1, int n2)
{
    int t1 = (int)n / c1;
    int min_c2 = (int)ceil((n - c1*(n1 > t1 ? t1 : n1)) / (double)c2);
    int t2 = (int)n / c2;
    int max_c2 = n2 > t2 ? t2 : n2;
    int t3 = max_c2 - min_c2 + 1;
    int count = t3 > 0 ? t3 : 0;
    return count;
}

int opt_solve(int n, int coins_count, int* coins) {
    int res = 0;

    for(int i = 0 ; i <= (int)n / 5 ; ++i)
    {
        //printf("%d\n", i);
        //printf("%d\n", n);
        res += sub_solve(5*i,5,10,coins[2], coins[3]) * sub_solve(n - 5*i,1,2,coins[0], coins[1]);
    }

    return res;
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

        int coins[4];

        int i;
        fl(i,0,4)
        {
            fastscan_int(&coins[i]);
        }

        int result = opt_solve(n, 4, coins);

        printf("%d", result);

        printf("\n");
    }

    return 0;
}
