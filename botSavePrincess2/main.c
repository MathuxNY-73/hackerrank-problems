#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void nextMove(int n, int r, int c, char grid[101][101]){
    int pr = -1 , pc = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < n ; ++j)
        {
            if(grid[i][j] == 'p')
            {
                pr = i;
                pc = j;
                break;
            }
        }
        if(pr != -1) {
            break;
        }
    }

    int diff_r = r - pr;
    int diff_c = c - pc;

    if(abs(diff_r) > abs(diff_c)) {
        if(diff_r > 0)
        {
            printf("UP");
        }
        else
        {
            printf("DOWN");
        }
    }
    else 
    {
        if(diff_c > 0)
        {
            printf("LEFT");
        }
        else
        {
            printf("RIGHT");
        }
    }
}

int main() {
    int n, r, c;

    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &c);

   char grid[101][101];
    
    for(int i=0; i<n; i++) {
        scanf("%s[^\n]%*c", grid[i]);
    }

    nextMove(n, r, c, grid);
    return 0;
}
