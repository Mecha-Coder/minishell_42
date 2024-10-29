#include "../include/minishell.h"

void destroy_env(t_shell *data)
{
    t_env *current;
    t_env *temp;

    current = data->env;
    while (current)
    {
        if (current->key)
            free(current->key);
        if (current->val)
            free(current->val);
        temp = current->next;
        free(current);
        current = temp;
    }
}