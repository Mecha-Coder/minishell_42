#include "../../include/minishell.h"

t_tree *create_node(void)
{
    t_tree *new;
    new = (t_tree *)malloc(sizeof(t_tree));
    if (new)
        memset(new, 0, sizeof(t_tree));
    return (new);
}