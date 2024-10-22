#include "../include/minishell.h"

/* polish_str_token
Purpopse: Transform string inside <STR> token into a useful form.

    Example: U'ser':"$USER"--> User:jpaul

Return:
    OK : TRUE
    KO : FALSE (Failed to tranforn due to malloc)
*/
int polish_str_token(t_token *token, t_env *list)
{
    int i;
    char *new;

    i = -1;
    while (token[++i].type == -1)
    {
        if (token[i].type == STR)
        {
            sub_single_quote(token[i].content, TRUE);
            del_double_quote(token[i].content);
            new = swap_var(token[i].content, list);
            if (new)
            {
                token[i].content = new;
                token[i].malloc = TRUE;
            }
            else
            {
                printf(FAIL_TRANSFORM "%s\n", token[i].content);
                return (FALSE);
            }
            del_single_quote(token[i].content);
            sub_single_quote(token[i].content, FALSE);
        }
    }
    return (TRUE);
}

