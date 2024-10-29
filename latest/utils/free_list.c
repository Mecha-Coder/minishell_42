#include "../include/minishell.h"

void free_list(char **list)
{
    int i;

    i = -1;
    while (list && list[++i])
        free (list[i]);
    if (list)
        free(list);
}