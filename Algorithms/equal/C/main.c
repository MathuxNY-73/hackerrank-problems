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
#define min(a,b) a<=b?a:b

char* readline();
char** split_string(char*);

int* minCoinChange(int(*)[3], int, int);

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}


// Complete the equal function below.
int equal(int arr_count, int* arr) {
    int coins[3] = {1,2,5};
    
    qsort(arr, arr_count, sizeof(int), compare);
    
    int* change = minCoinChange(&coins, 3, arr[arr_count - 1] + coins[2]);
    
    int min = arr[0];
    int best_move = 9999999;
    for(int i = 0 ; i < coins[2] ; ++i)
    {
        int score = 0;
        for(int j = 0 ; j < arr_count ; ++j)
        {
            score += change[arr[j] - min + i];
        }
        best_move = min(best_move, score);
    }
    
    free(change);
    
    return best_move;
}

int* minCoinChange(int (*coins)[], int c_count, int n)
{
    int* res = malloc(sizeof(int) * (n + 1));
    memset(res, 9999999, (n+1) * sizeof(int));
    
    qsort(coins, c_count, sizeof(int), compare);
    
    for(int i = 0 ; i < (*coins)[0] && i < n+1 ; ++i)
    {
        res[i] = 0;
    }
    
    for(int i = 0 ; i < c_count ; ++i)
    {
        for(int j = (*coins)[i] ; j < n + 1 ; ++j)
        {
            res[j] = min(res[j], res[j - (*coins)[i]] + 1);
        }
    }
    
    return res;
}

void fastscan(int* number)
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
    fastscan(&t);

    wl(t)
    {
        int n = 0;
        fastscan(&n);

        int* colleagues = malloc(sizeof(int) * n);

        int i;
        fl(i,0,n)
        {
            fastscan(&colleagues[i]);
        }

        int result = equal(n,colleagues);

        printf("%d\n", result);

        free(colleagues);
    }

    return 0;
}
