#include "../include/minishell.h"

int show_token(t_shell *data)
{
    int i;

    i = -1;
    printf("\n\n");
    while (data->token[++i].type)
    {
        if (data->token[i].type == OR)         printf("%-7s\n","<OR>");
        else if (data->token[i].type == PIPE)  printf("%-7s\n","<PIPE>");
        else if (data->token[i].type == HERE)  printf("%-7s\n","<HERE>");
        else if (data->token[i].type == RD)    printf("%-7s\n","<RD>");
        else if (data->token[i].type == APPD)  printf("%-7s\n","<APPD>");
        else if (data->token[i].type == WR)    printf("%-7s\n","<WR>");
        else if (data->token[i].type == AND)   printf("%-7s\n","<AND>");
        else if (data->token[i].type == OB)    printf("%-7s\n","<OB>");
        else if (data->token[i].type == CB)    printf("%-7s\n","<CB>");
        else if (data->token[i].type == STR)   
            printf("%-7s %s\n","<STR>", data->token[i].content);
    }
    return (TRUE);
}