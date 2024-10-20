#include "../include/minishell.h"

char *special_join(char *s1, char *s2, char *s3)
{
    char *new;
    int i = 0;

    new = (char *)malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);
    if (new)
    {
        while(*s1)
            new[i++] = *s1++;
        while(*s2)
            new[i++] = *s2++;
        while(*s3)
            new[i++] = *s3++;
        new[i] = '\0';
    }
    return (new);
}

/*
int main()
{
    char s[] = "This_$USER$HOME";
    int size = 4;

    char sub[] = "jpaul";
    int i = 5;

    s[i] = '\0';
    char *new = special_join(s, sub, &s[i + size + 1]);
    printf("%s\n", new);
    free(new);
}

Test case
$USER
$USER$HOME
User:_$USER
This_$USER$HOME
*/