#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define INF 9999999999

long giveCandies(int, const int[]);
void printArray(int, const int[]);

typedef struct node {
    int i;
    struct node* n;
} node;

typedef struct linkedL {
    node* h;
    node* t;
} linkedL;

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
    int* candies = malloc(sizeof(int) * ar_size);
    node** p = malloc(sizeof(node*) * ar_size);
    long res = 0;

    for(int i = 0; i < ar_size ; ++i)
    {
        p[i] = NULL;
        candies[i] = 1;
    }

    for(int i = 0; i < ar_size ; ++i)
    {
        if(i < ar_size - 1)
        {
            if(ar[i] < ar[i+1])
            {
                node* n = malloc(sizeof(node));
                n->i = i+1;
                n->n = p[i];
                p[i] = n;
            }
            else if(ar[i] > ar[i+1])
            {
                node* n = malloc(sizeof(node));
                n->i = i;
                n->n = p[i+1];
                p[i+1] = n;
            }
        }
    }

    for(int i = 0 ; i < ar_size ; ++i)
    {
        linkedL q;
        node* qn = malloc(sizeof(node));
        qn->i = i;
        qn->n = NULL;
        q.h = qn;

        while(q.h != NULL)
        {
            node* cqn = q.h;
            int ci = cqn->i;

            q.h = cqn->n;
            free(cqn);
            if (q.h == NULL) q.t = NULL;

            node* pi = p[ci];
            while(pi != NULL)
            {
                if(candies[pi->i] <= candies[ci])
                {
                    ++candies[pi->i];
                    node* qn = malloc(sizeof(node));
                    qn->i = pi->i;
                    if(q.t == NULL)
                    {
                        qn->n = NULL;
                        q.h = qn;
                        q.t = qn; 
                    }
                    else
                    {
                        q.t->n = qn;
                        q.t = qn;
                    }
                }
                pi = pi->n;
            }
        }
    }

    //printArray(ar_size, candies);

    for(int i = 0 ; i < ar_size ; ++i)
    {
        res += candies[i];
    }

    // Free stuff
    for(int i = 0 ; i < ar_size ; ++i)
    {
        node* c = p[i];
        while(c != NULL)
        {
            node* f = c;
            c = f->n;
            free(f);
        }
    }

    return res;
}

void printArray(int s, const int ar[])
{
    for(int i = 0 ; i < s ; ++i)
    {
        printf("%d ", ar[i]);
    }
    puts("");
}
