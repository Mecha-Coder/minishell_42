#include "../include/minishell.h"

void show_env(t_shell *data)
{
    t_env *current;
    int i = 0;

    current = data->env;
    while (current)
    {
        printf("%d) %s=%s\n", ++i, current->key, current->val);
        current = current->next;
    }
}