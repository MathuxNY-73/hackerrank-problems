#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long unsigned int aVeryBigSum(int, long int*);

int main() {
    int n; 
    scanf("%i", &n);
    long int *ar = malloc(sizeof(long int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%li",&ar[ar_i]);
    }
    long unsigned int result = aVeryBigSum(n, ar);
    printf("%ld\n", result);
    return 0;
}

long unsigned int aVeryBigSum(int ar_size, long int* ar)
{
     long unsigned int res = 0;
     
     for (int i = 0 ; i < ar_size ; ++i)
     {
        res += ar[i];
     }

     return res;
}
