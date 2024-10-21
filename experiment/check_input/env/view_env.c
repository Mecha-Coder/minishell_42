#include "../include/minishell.h"

void view_env(t_data *data)
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