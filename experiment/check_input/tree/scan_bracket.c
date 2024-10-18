#include "../include/minishell.h"

int  scan_bracket(t_tree *node)
{
    int i;
    int bracket;
    
    (i = -1, bracket = 0);
    while (node->token[i + 1].type != -1)
        i++;

    while (i > -1)
    {
        if (node->token[i].type == CB)
        {
            bracket++;
            if (bracket == 1)
                node->token[i].type = -1;
        }
        else if (node->token[i].type == OB)
            bracket--;
        if (!bracket && node->token[i].type == OB)
        {
            node->token = &node->token[i + 1];
            node->type = SUB;
            return (TRUE);
        }
        i--;
    }
    return (FALSE);
}