#include "../include/minishell.h"


int descent_tree(t_tree *node, t_env *list)
{
    if (node->type == CMD)
        return (run_cmd(node, list));
    return (FALSE);
}

void run_ast(t_shell *data)
{
    descent_tree(data->tree, data->env);
}