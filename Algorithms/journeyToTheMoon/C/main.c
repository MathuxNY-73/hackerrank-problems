#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void setUnion(int* rank, int* set, int r, int l)
{
    if(rank[r] > rank[l])
    {
        set[l] = r;
    }
    else
    {
        set[r] = l;
        if(rank[r] == rank[l])
        {
            ++rank[r];
        }
    }
}

int findSet(int* set, int i) {
    if(set[i] != i)
    {
        set[i] = findSet(set, set[i]);
    }
    return set[i];
}

int main(int argc, char* argv[]) {

    int n = 0, p = 0;
    scanf("%d %d",&n, &p);

    int* ranks = malloc(sizeof(int) * n);
    int* sets  = malloc(sizeof(int) * n);
    int* counts = malloc(sizeof(int) * n);

    for(int i = 0; i < n ; ++i)
    {
        sets[i] = i;
        ranks[i] = 0;
        counts[i] = 0;
    }

    for (int i = 0; i < p ; ++i)
    {
        int r,l;
        scanf("%d %d",&r, &l);
        setUnion(ranks, sets, findSet(sets, r), findSet(sets, l));
    }

    for(int i = 0 ; i < n ; ++i)
    {
        ++counts[findSet(sets,i)];
    }

    unsigned long res = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        res += counts[i] * (n - counts[i]);
    }

    printf("%lu", res/2);

    free(ranks);
    free(sets);
    free(counts);
    return 0;
}
