#include "../include/minishell.h"

int token_len(t_token *token)
{
    int i;

    i = 0;
    while (token[i].type != -1)
        i++;
    return (i);
}