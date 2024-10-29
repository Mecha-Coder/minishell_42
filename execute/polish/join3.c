#include "../../include/minishell.h"

int get_len(char *s);

/* Test 
Test case
$USER
$USER$HOME
User:_$USER
This_$USER$HOME

int main()
{
    char s[] = "This_$USER$HOME";
    int size = 4;

    char *sub= "[new]";
    int i = 5;

    s[i] = '\0';
    char *new = join3(s, sub, &s[i + size + 1]);
    printf("%s\n", new);
    free(new);
}
*/

char *join3(char *s1, char *s2, char *s3)
{
    char *new;
    int total;
    int i;

    (i = 0, total = 0);
    total += get_len(s1);
    total += get_len(s2);
    total += get_len(s3);

    new = (char *)malloc(total + 1);
    
    if (new)
    {
        while (s1 && *s1)
            new[i++] = *s1++;
        while (s2 && *s2)
            new[i++] = *s2++;
        while (s3 && *s3)
            new[i++] = *s3++;
        new[i] = '\0';
    }
    return (new);
}

int get_len(char *s)
{
    if (s)
        return (strlen(s));
    return (0);
}