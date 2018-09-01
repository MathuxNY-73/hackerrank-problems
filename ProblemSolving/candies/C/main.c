#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define INF 9999999999

long giveCandies(int, const int[]);
int compareTuple( const void* , const void* );

typedef struct node {
    int i;
    struct node* n;
} node;

typedef struct tuple {
    int idx;
    int value;
} tuple;


int main() {
    int n; 
    scanf("%i", &n);
    int *ar = malloc(sizeof(int) * n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       scanf("%i",&ar[ar_i]);
    }
    long sum = giveCandies(n, ar);
    printf("%ld\n", sum);

    return 0;
}

long giveCandies(int ar_size, const int ar[])
{
    int candies[ar_size];
    node* c[ar_size];
    tuple art[ar_size];
    long res = 0;

    for(int i = 0; i < ar_size ; ++i)
    {
        c[i] = NULL;
        art[i].idx = i;
        art[i].value = ar[i];
        candies[i] = 1;
    }

    for(int i = 0; i < ar_size ; ++i)
    {
        if(i < ar_size - 1)
        {
            if(ar[i] > ar[i+1])
            {
                node* n = malloc(sizeof(node));
                n->i = i+1;
                n->n = c[i];
                c[i] = n;
            }
            else if(ar[i] < ar[i+1])
            {
                node* n = malloc(sizeof(node));
                n->i = i;
                n->n = c[i+1];
                c[i+1] = n;
            }
        }
    }

    qsort(art, ar_size, sizeof(tuple), compareTuple);

    for(int i = 0 ; i < ar_size ; ++i)
    {
        if(c[art[i].idx] != NULL)
        {
            int max = 1;
            for(node* cur = c[art[i].idx] ; cur != NULL ; cur = cur->n)
            {
                if(candies[cur->i] > max)
                {
                    max = candies[cur->i];
                }
            }
            candies[art[i].idx] = max + 1;
        }
    }

    for(int i = 0 ; i < ar_size ; ++i)
    {
        res += candies[i];
    }

    for(int i = 0 ; i < ar_size ; ++i)
    {
        for(node* cur = c[i] ; cur != NULL ;)
        {
            node* tmp = cur->n;
            free(cur);
            cur = tmp;
        }
    }

    return res;
}

int compareTuple( const void* a, const void* b)
{
    tuple ta = * ( (tuple*) a );
    tuple tb = * ( (tuple*) b );

     if ( ta.value == tb.value ) return ta.idx - tb.idx;
     else if ( ta.value < tb.value ) return -1;
     else return 1;
}
