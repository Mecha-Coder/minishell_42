#include "../include/minishell.h"

static void show_token_2(t_token *token)
{
    int i;

    i = -1;
    while(token[++i].type)
    {
        if (token[i].type == OR)         printf("%s","<OR>");
        else if (token[i].type == PIPE)  printf("%s","<PIPE>");
        else if (token[i].type == HERE)  printf("%s","<HERE>");
        else if (token[i].type == RD)    printf("%s","<RD>");
        else if (token[i].type == APPD)  printf("%s","<APPD>");
        else if (token[i].type == WR)    printf("%s","<WR>");
        else if (token[i].type == AND)   printf("%s","<AND>");
        else if (token[i].type == OB)    printf("%s","<OB>");
        else if (token[i].type == CB)    printf("%s","<CB>");
        else if (token[i].type == STR)   printf("%s%s ","<STR>",token[i].content);
    }
}

/*
static void show_cmd(char **cmd)
{
    int i;

    i = -1;
    printf("  CMD: ");
    while (cmd[++i])
        printf("%s, ", cmd[i]);
}
*/

static void show_info(t_tree *node)
{
    if (node->type == OR)         printf("OR");
    else if (node->type == PIPE)  printf("PIPE");
    else if (node->type == AND)   printf("AND");
    else if (node->type == CMD || node->type == SUB)
    {
        if (node->type == CMD)  printf("%-7s","CMD");
        if (node->type == SUB)  printf("%-7s","SUB");
        show_token_2(node->token);
        //show_cmd(node->cmd);
    }   
    printf("\n");
}

static void print_indent_level(int i)
{
    while (i > 1 && i--)
        printf("      ");
    if (i)
        printf("|_____");
}

static void visualize_tree(t_tree *node, int level)
{
    if (!node)
        return;
    print_indent_level(level);
    show_info(node);
    level++;
    visualize_tree(node->left, level);
    visualize_tree(node->right, level);
}

void show_ast(t_shell *data)
{   
    printf("\n\n");
    visualize_tree(data->tree, 0);
    printf("\n");
}