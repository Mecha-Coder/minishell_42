#include "../include/token.h"

void show_str(t_data *data)
{
    int i = -1;

    while (++i < data->s_len)
    {
        if (data->s[i] == '\0')   
            printf("#");
        else                
            printf("%c", data->s[i]);
    }
    printf("\n\n");
}

void show_token(t_data *data)
{
    int i;

    i = -1;
    printf("\n\n");
    while(data->token[++i].type >= 0)
    {
        if (data->token[i].type == OR)         printf("%-7s\n","<OR>");
        else if (data->token[i].type == PIPE)  printf("%-7s\n","<PIPE>");
        else if (data->token[i].type == HERE)  printf("%-7s\n","<HERE>");
        else if (data->token[i].type == RD)    printf("%-7s\n","<RD>");
        else if (data->token[i].type == APPD)  printf("%-7s\n","<APPD>");
        else if (data->token[i].type == WR)    printf("%-7s\n","<WR>");
        else if (data->token[i].type == AND)   printf("%-7s\n","<AND>");
        else if (data->token[i].type == XAND)  printf("%-7s\n","<XAND>");
        else if (data->token[i].type == OB)    printf("%-7s\n","<OB>");
        else if (data->token[i].type == CB)    printf("%-7s\n","<CB>");
        else if (data->token[i].type == STR)   
            printf("%-7s %s\n","<STR>", data->token[i].content);
    }
}

void tokenize(t_data *data)
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
    data->token[j] = (t_token){-1, -1, NULL};
    sort_token(data);
    show_token(data);
}
