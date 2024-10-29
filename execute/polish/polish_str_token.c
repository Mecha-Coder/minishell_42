#include "../../include/minishell.h"

void del_double_quote(char *s);
void del_single_quote(char *s);
int contain_var(char *s);

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

    i = -1;
    while (token[++i].type)
    {
        if (token[i].type == STR)
        {   
            sub_single_quote(token[i].content, TRUE);
            del_double_quote(token[i].content);
            if (contain_var(token[i].content))
            {
                token[i].content = swap_var(token[i].content, list);
                if (token[i].content)
                    token[i].malloc = TRUE;
                else
                    return (printf(FAIL_SWAP "%s\n", token[i].content), 
                        FALSE);
            } 
            del_single_quote(token[i].content);
            sub_single_quote(token[i].content, FALSE);
        }
    }
    return (TRUE);
}

int contain_var(char *s)
{
    int i;
    int detect;
    int len;
  
    (i = -1, detect = TRUE);
    while (s && s[++i])
    {
        if (s[i] == '\'')
            detect = !detect;
        if (detect && s[i] == '$' && is_identifier(&s[i + 1], &len))
            return (TRUE);
    }
    return (FALSE);
}

void del_double_quote(char *s)
{
    int i;
    int j;
    int detect;

    (i = -1, detect = TRUE);
    while (s[++i])
    {
        if (s[i] == '\'') 
            detect = !detect;
        if (detect && s[i] == '\"')
        {
            j = -1;
            while (++j, s[i + j])
                s[i + j] = s[i + j + 1];
            i = -1;
        }
    }
}

void del_single_quote(char *s)
{
    int i;
    int j;

    i = -1;
    while (s[++i])
    {
        if (s[i] == '\'')
        {
            j = -1;
            while (++j, s[i + j])
                s[i + j] = s[i + j + 1];
            i = -1;
        }
    }
}
