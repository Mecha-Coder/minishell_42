#include "../include/minishell.h"

void trim_off(char *s, int size)
{
    int i = 0;
    
    while (s[size + i])
    {
        s[i] = s[size + i];
        i++;
    }
    while (s[i])
        s[i++] = '\0';
}

/*
int main()
{
    char s[] = "Nice_house$MAN$?";

    printf("%s\n", s);
    trim_off(&s[10], 3 + 1);
    printf("%s\n", s);
}
*/


