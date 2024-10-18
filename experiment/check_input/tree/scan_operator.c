#include "../include/minishell.h"

int scan_operator(t_tree *node)
{
    int i;
    int bracket;
    
    (i = -1, bracket = 0);
    while (node->token[i + 1].type != -1)
        i++;


    while (i > -1)
    {
        if (node->token[i].type == CB)
            bracket++;
        else if (node->token[i].type == OB)
            bracket--;
        else if (!bracket 
            && (node->token[i].type == PIPE 
            || node->token[i].type == OR
            || node->token[i].type == AND))
        {
            branch(node ,i);
            return (TRUE);
        }
        i--;
    }
    return (FALSE);
}