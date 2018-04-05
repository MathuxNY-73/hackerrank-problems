#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int mandragora(int, int*);
int compare_int(const void*, const void* b);

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%i", &n);
        int *H = malloc(sizeof(int) * n);
        for (int H_i = 0; H_i < n; H_i++) {
           scanf("%i",&H[H_i]);
        }
        long int result = mandragora(n, H);
        printf("%ld\n", result);
    }
    return 0;
}

long int mandragora(int H_size, int* H) {
    int s = 1;
    long int h = 0;
    long int p = 0;

    qsort(H, H_size, sizeof(int), compare_int);

    for (int i = 0 ; i < H_size ; ++i) {
        h += H[i];
    }

    p = s * h;
    for (int i = 0 ; i < H_size ; ++i) {
        long int pt = p - (long int)s * H[i] + (h - H[i]);

        if(pt <= p) {
            break;
        }

        h = h - H[i];
        p = pt;
        ++s;
    }

    return p;
}

int compare_int(const void* a, const void* b) 
{
    return (int) (*(int*)a - *(int*)b);
}
