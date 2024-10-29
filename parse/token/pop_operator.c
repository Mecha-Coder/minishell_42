#include "../../include/minishell.h"

static void initialize_pattern(char pattern[10][3]);
static void subtitute_null(char *s, int i, int size);

/* pop_operator
Purpose: Search word in command that matches "initialize_pattern".
    Append token list with operator found, then swap with NULL char.

    Example    :  cat < in.txt && ls --> cat \0  in.txt \0\0 ls
    Token list : <RD><AND>
Return
    pointer j : track the current token index 
*/
void pop_operator(t_shell *data, int *j)
{
    int i;
    int index;
    char pattern[11][3];
    
    i = 1;
    initialize_pattern(pattern);
    while(*j < CMD_SIZE && pattern[i][0])
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

static void initialize_pattern(char pattern[10][3])
{
    strcpy(pattern[OR], "||");
    strcpy(pattern[PIPE], "|");
    strcpy(pattern[HERE], "<<");
    strcpy(pattern[RD], "<");
    strcpy(pattern[APPD], ">>");
    strcpy(pattern[WR], ">");
    strcpy(pattern[AND], "&&");
    strcpy(pattern[OB], "(");
    strcpy(pattern[CB], ")");
    pattern[10][0] = '\0';
}

static void subtitute_null(char *s, int i, int size)
{
    while(size--)
        s[i++] = '\0';
}