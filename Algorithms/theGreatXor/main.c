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
long makeMask(long);

// Complete the theGreatXor function below.
long theGreatXor(long x) {
    long mask = makeMask(x);
    return ~x & mask;
}

long makeMask(long x)
{
    long mask = LONG_MAX;
    if(x == 0)
    {
        return ~mask;
    }

    long l = 1;
    int i = 0;
    for(;l <= x; ++i)
    {
        l = l << 1;
    }

    return ~(mask << i);
}

int main()
{
    FILE* fptr = stdout;

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* x_endptr;
        char* x_str = readline();
        long x = strtol(x_str, &x_endptr, 10);

        if (x_endptr == x_str || *x_endptr != '\0') { exit(EXIT_FAILURE); }

        long result = theGreatXor(x);

        fprintf(fptr, "%ld\n", result);
    }

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
