#include "../include/minishell.h"

int run_cmd(t_tree *node, t_shell *data)
{
    if (polish_str_token(node->token, data))
    {
        prep_cmd(node);
        if (!strcmp(node->cmd[0],"echo"))
            builtin_echo(node->cmd);
        else
            return (none_builtin(node, list));
    }
    return (EXIT_SUCCESS);
}
