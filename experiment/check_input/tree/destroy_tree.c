#include "../include/minishell.h"

void destroy_tree(t_tree *node)
{
    if (!node)
        return ;
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
    node = NULL;
}