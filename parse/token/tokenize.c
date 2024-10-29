#include "../../include/minishell.h"

/*Test
void show_str(t_shell *data)
{
    int i = -1;

    while (++i < data->s_len)
    {
        if (data->s[i] == '\0') printf("#");
        else                    printf("%c", data->s[i]);
    }
    printf("\n\n");
}

int tokenize(t_shell *data)
{
    int j;

    j = 0;
    printf("\n\n%s\n\n", data->s);
    printf("\nStage1: Pop operator\n"
            "=====================\n");
    pop_operator(data, &j);
    show_str(data);
    printf("\nStage2: Link str\n"
            "=====================\n");
    pop_str(data, &j);
    show_str(data);
    data->token[j] = (t_token){-1, -1, NULL, FALSE};
    sort_token(data);
    show_token(data);
    return 1;
}

int main()
{
    t_shell data;
    char s[] = "env | grep SHLVL && (env | grep SHLVL)";

    strcpy(data.s, s);
    data.s_len = strlen(s);
    tokenize(&data);
}
*/

/* tokenize
Purpose: Break string into its smallest unit & label them.
   Tokens are stored in a array list
    
    Example   :  cat  <  in.txt &&  ls
    Token list: <STR><RD><STR><AND><STR>
    Label     :   9   3    9    6    9
Return:
    OK: TRUE
    KO: FALSE (Failed if command too long, Limit to 100 commands)
*/
int tokenize(t_shell *data)
{
    int j;

    j = 0;
    if ((pop_operator(data, &j), j < CMD_SIZE) 
        && (pop_str(data, &j),  j < CMD_SIZE))
    {
        data->token[j] = (t_token){0, -1, NULL, FALSE};
        sort_token(data);
        data->token_len = token_len(data->token);
        return (TRUE);
    }
    return (printf(FAIL_TOKEN), FALSE);
}
