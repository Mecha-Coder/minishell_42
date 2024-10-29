#include "../../include/minishell.h"

/* clear_str_token
Purpose: Check if <STR> token malloc status = TRUE.
    If yes free content.
*/
void free_str_token(t_shell *data)
{
    int i;

    i = -1;
    while (++i < data->token_len)
    {
        if (data->token[i].malloc
            && data->token[i].content)
        {
            free(data->token[i].content);
        }
    }
}