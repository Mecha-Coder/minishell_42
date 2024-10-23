#include "../include/minishell.h"

int descent_tree(t_tree *node, t_env *list)
{
    if (!node)
        return (FALSE);
    if (node->type == CMD)
    {
        if (polish_str_token(node->token, list))
        {;}
    }
    descent_tree(node->left, list);
    descent_tree(node->right, list);
    return (TRUE);
}

void run_ast(t_shell *data)
{
    descent_tree(data->tree, data->env);
}
