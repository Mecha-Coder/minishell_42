#include "../include/minishell.h"

int descent_tree(t_tree *node, t_shell *data)
{
    if (node->type == CMD)
        return (run_cmd(node, data));
    if (node->type == PIPE)
        return (run_pipe(node, data));
    return (FALSE);
}

void run_ast(t_shell *data)
{
    data->exit_code = descent_tree(data->tree, data);
}