#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    int i = -1; 
    
    (void)ac;
    (void)av;
    while (env[++i])
        printf("%s\n", env[i]);
    return (0);
}