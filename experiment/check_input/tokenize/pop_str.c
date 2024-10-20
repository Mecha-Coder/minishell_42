#include "../include/minishell.h"

static int blank(char c)
{
    return (c == ' ' || c == '\0');
}

void pop_str(t_data *data, int *j)
{
    int i;
    int detect;
    int isstr;

    (i = -1, detect = ON, isstr = FALSE);
    while(*j < TOKEN_SIZE && ++i < data->s_len)
    {
        detection(data->s[i], &detect);
        if (!blank(data->s[i]) && isstr == FALSE)
        {
            isstr = TRUE;
            data->token[(*j)++] = (t_token){STR, i, &data->s[i], FALSE};
        }
        else if (blank(data->s[i]) && detect == ON)
        {
            data->s[i] = '\0';
            isstr = FALSE;
        }
    }    
}