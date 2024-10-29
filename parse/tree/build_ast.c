#include "../../include/minishell.h"

int build_tree(t_tree *node);

/* Test - Run with script
int main(int ac, char **av)
{
    t_shell data;

    if (ac != 2 || isempty(av[1]))     return (0);
    if (strlen(av[1]) >= BUFFER_SIZE)  return (printf(LONG_INPUT), FALSE);
    
    data.input = av[1];
    strcpy(data.s, av[1]);
    data.s_len = strlen(av[1]);

    if (check_syntax_before(&data)
        && tokenize(&data)
        && check_syntax_after(&data)
        && build_ast(&data))
    {
        printf("\n\n%s\n", data.input);
        show_ast(&data);
        clear_ast(&data);
    }
    return (0);
}
*/

/* build_ast
Purpose: Based on the token list, create Abstract Syntax Tree (AST)
Result: 
    OK: TRUE
    KO: FALSE (failed due to malloc issue)
*/
int build_ast(t_shell *data)
{
    data->tree = create_node();
    if (data->tree)
    {
        data->tree->token = data->token;
        if (build_tree(data->tree))
            return (TRUE);
    }
    printf(FAIL_AST);
    destroy_ast(data);
    return (FALSE);
}

int build_tree(t_tree *node)
{
    if (!node)
        return (FALSE);
    if (scan_operator(node))
    {
        if (!build_tree(node->left) 
            || !build_tree(node->right))
            return (FALSE);
    }
    else if (!scan_bracket(node))
        node->type = CMD;
    return (TRUE);
}