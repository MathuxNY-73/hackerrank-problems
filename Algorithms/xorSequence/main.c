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

// Complete the xorSequence function below.
long xorSequence(long l, long r) {
    long res = 0;

    int r_mod = r % 4;
    int l_mod = l % 4;

    long l_d = ceil(l / 4.0l);
    long r_d = floor(r / 4.0l);

    long d = labs(r_d - l_d);

    if(d % 2 == 1)
    {
        res = 2;
    }

    if(r_mod == 0 || r_mod == 1)
    {
        res ^= r;
    }
    else if(r_mod == 2 || r_mod == 3)
    {
        res ^= 2;
    }

    if(l_mod == 1 || l_mod == 2)
    {
        res ^= (l + 1);
    }

    return res;
}

int main()
{
    FILE* fptr = stdout;

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char** lr = split_string(readline());

        char* l_endptr;
        char* l_str = lr[0];
        long l = strtol(l_str, &l_endptr, 10);

        if (l_endptr == l_str || *l_endptr != '\0') { exit(EXIT_FAILURE); }

        char* r_endptr;
        char* r_str = lr[1];
        long r = strtol(r_str, &r_endptr, 10);

        if (r_endptr == r_str || *r_endptr != '\0') { exit(EXIT_FAILURE); }

        long result = xorSequence(l, r);

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
