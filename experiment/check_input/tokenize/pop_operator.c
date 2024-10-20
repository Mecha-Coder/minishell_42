#include "../include/minishell.h"

static void initialize_pattern(char pattern[11][3])
{
    strcpy(pattern[OR], "||");
    strcpy(pattern[PIPE], "|");
    strcpy(pattern[HERE], "<<");
    strcpy(pattern[RD], "<");
    strcpy(pattern[APPD], ">>");
    strcpy(pattern[WR], ">");
    strcpy(pattern[AND], "&&");
    strcpy(pattern[XAND], "&");
    strcpy(pattern[OB], "(");
    strcpy(pattern[CB], ")");
    pattern[10][0] = '\0';
}

static void subtitute_null(char *s, int i, int size)
{
    while(size--)
        s[i++] = '\0';
}

void pop_operator(t_data *data, int *j)
{
    int i;
    int index;
    char pattern[11][3];
    
    i = 0;
    initialize_pattern(pattern);
    while(*j < TOKEN_SIZE && pattern[i][0])
    {   
        index = find_word(data->s, data->s_len, pattern[i]);
        if (index >= 0)
        {
            data->token[(*j)++] = (t_token){i, index, NULL, FALSE};
            subtitute_null(data->s, index, strlen(pattern[i]));
        }
        else
            i++;
    }
}