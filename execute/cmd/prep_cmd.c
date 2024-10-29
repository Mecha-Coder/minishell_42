#include "../../include/minishell.h"

void prep_cmd(t_tree *node)
{
    int len;
    int i;

    (i = -1, len = token_len(node->token));
    while (++i < len)
    {
        if (node->token[i].type == STR)
        {
            node->cmd[i] = node->token[i].content;
            node->token[i].type = 0;
        }
    }
}