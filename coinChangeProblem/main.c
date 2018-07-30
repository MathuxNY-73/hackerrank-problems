#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

long getWaysMemory(long, int, long*, long*);
void initWays(long, long*);

// Complete the getWays function below.
long getWays(long n, int c_count, long* c) {
    long* ways = malloc((n + 1) * sizeof(long));
    initWays(n + 1, ways);

    return getWaysMemory(n, c_count, c, ways);
}

void initWays(long size, long* ways)
{
    for(int i = 0 ; i < size ; ++i)
    {
        ways[i] = -1;
        printf("Hello World 6: ways[%d] = %ld\n", i, ways[i]);
    }

    ways[0] = 0;
}

bool isIn(long n, int size, long* a)
{
    for (int i = 0 ; i < size; ++i)
    {
        if(a[i] == n)
        {
            return true;
        }
    }
    return false;
}

long getWaysMemory(long n, int c_count, long* c, long* ways)
{
    printf("Hello World 0: %ld, ways[%ld] = %ld\n", n, n, ways[n]);
    if (ways[n] <= -1)
    {
        ways[n] = 0;
        long* studied = malloc(c_count * 2 * sizeof(long));
        for(int i = 0 ; i < c_count * 2 ; ++i)
        {
            studied[i] = -99999999;
        }

        for(int i = 0 ; i < c_count ; ++i)
        {
            printf("Hello World 5: %ld\n", c[i]);
            long diff = n - c[i];
            if(isIn(diff, c_count * 2, studied))
            {
                continue;
            }

            studied[i * 2] = c[i];
            studied[i * 2 + 1] = diff;

            if(diff == 0)
            {
                ++ways[n];
                continue;
            }

            if(diff < 0)
            {
                continue;
            }

            long w = getWaysMemory(diff, c_count, c, ways);
            if(w > 0)
            {
                ways[n] += w;
            }
        }
    }
    printf("Hello World 7: %ld, ways[%ld] = %ld\n", n, n, ways[n]);
    return ways[n];
}

int main()
{
    FILE* fptr = stdout;

    char** nm = split_string(readline());
    printf("Hello World 2\n");

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** c_temp = split_string(readline());

    long* c = malloc(m * sizeof(long));

    printf("Hello World 3\n");

    for (int i = 0; i < m; i++) {
        char* c_item_endptr;
        char* c_item_str = *(c_temp + i);
        long c_item = strtol(c_item_str, &c_item_endptr, 10);

        if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(c + i) = c_item;
    }

    int c_count = m;
    printf("Hello World 1\n");

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    long ways = getWays(n, c_count, c);

    fprintf(fptr, "%ld\n", ways);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
