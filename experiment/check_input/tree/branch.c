#include "../include/minishell.h"

void branch(t_tree *node, int i)
{
    node->type = node->token[i].type;
    node->token[i].type = -1;

    node->left = create_node();
    node->right = create_node();

    node->left->token = &node->token[0];
    node->right->token = &node->token[i + 1];
}