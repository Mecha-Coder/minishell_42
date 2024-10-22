#include "../include/minishell.h"

void build_tree(t_tree *node)
{
    if (scan_operator(node))
    {
        build_tree(node->left);
        build_tree(node->right);
    }
    else if (!scan_bracket(node))
        node->type = CMD;
}