#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SEN_LENGTH 100
#define MAX_S_LENGTH 20

int main()
{
    char ch;
    char s[MAX_S_LENGTH];
    char sen[MAX_SEN_LENGTH];
    scanf("%c\n", &ch);
    scanf("%[^\n]%*c\n", s);
    scanf("%[^\n]%*c", sen);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    return 0;
}


