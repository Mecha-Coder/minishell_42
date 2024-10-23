#include "../include/minishell.h"

/* clear_str_token
Purpose: Check if <STR> token malloc status = TRUE.
    If yes free content.
*/
void free_str_token(t_shell *data)
{
    int i;

    i = -1;
    while (data->token[++i].type != -1)
    {
        if (data->token[i].type == STR && data->token[i].malloc)
            free(data->token[i].content);
    }
}