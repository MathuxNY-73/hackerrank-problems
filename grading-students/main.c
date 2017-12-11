#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int grades_size, int* grades, int *result_size){

    int* results = malloc(sizeof(int) * grades_size);
    *result_size = 0;

    for(int grades_i = 0; grades_i < grades_size; ++grades_i)
    {
        int grade = *(grades + grades_i);
        int next_multiples_of_5 = (floor(grade / 5) + 1) * 5;
        if(grade < 38 || next_multiples_of_5 - grade >= 3)
        {
            *(results + grades_i) = grade;
        }
        else
        {
            results[grades_i] = next_multiples_of_5;
        }

        ++(*result_size);
    }

    return results;
}

int main() {
    int n; 
    scanf("%d", &n);
    int *grades = malloc(sizeof(int) * n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       scanf("%d",&grades[grades_i]);
    }
    int result_size;
    int* result = solve(n, grades, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    

    return 0;
}
