#include "../../include/minishell.h"

static int space(char c);

/* pop_str
Purpose: Do post-scan after pop-operator. Remainder are <STR> 
    Fill space with NULL char. Linked word & append token list

    Example    :  cat \0  in.txt \0\0 ls --> cat\0\0\0in.txt\0\0\0ls
    Token list : <RD><AND><STR>  <STR>  <STR>
                           cat  in.txt   ls
Return
    pointer j : track the current token index 
*/
void pop_str(t_shell *data, int *j)
{
    int i;
    int detect;
    int isstr;

    (i = -1, detect = ON, isstr = FALSE);
    while(*j < CMD_SIZE && ++i < data->s_len)
    {
        detection(data->s[i], &detect);
        if (!space(data->s[i]) && isstr == FALSE)
        {
            isstr = TRUE;
            data->token[(*j)++] = (t_token){STR, i, &data->s[i], FALSE};
        }
        else if (space(data->s[i]) && detect == ON)
        {
            data->s[i] = '\0';
            isstr = FALSE;
        }
    }
}

static int space(char c)
{
    return (c == ' ' || c == '\0');
}