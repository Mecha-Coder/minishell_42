#include "../../include/minishell.h"

static void clear_tree(t_tree *node)
{
    if (!node)
        return ;
    clear_tree(node->left);
    clear_tree(node->right);
    free(node);
}

void destroy_ast(t_shell *data)
{
    clear_tree(data->tree);
}