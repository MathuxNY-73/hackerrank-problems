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
int* findPoint(int px, int py, int qx, int qy, int* result_count) {
    int* arr = malloc(sizeof(int) * 2);
    *result_count = 2;
    
    arr[0] = 2*qx - px;
    arr[1] = 2*qy - py;
    
    return arr;
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
        int px =0, py=0, qx=0, qy=0;
        fastscan_int(&px);
        fastscan_int(&py);
        fastscan_int(&qx);
        fastscan_int(&qy);

        int result_count;

        int* res = findPoint(px, py, qx, qy, &result_count);

        for(int i = 0 ; i < result_count ; ++i)
        {
            printf("%d ", res[i]);
        }
        printf("\n");

        free(res);
    }

    return 0;
}
