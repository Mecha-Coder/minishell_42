#include "../../include/minishell.h"

void branch(t_tree *node, int i);

/* scan_operator                <-
Purpose: Scan token list from right to left.
    Branch tree when find operator ||, | and &&
Result:
    OK: Found operator
    KO: No operator in token list

Note: skip when in bracket pairs
*/
int scan_operator(t_tree *node)
{
    int i;
    int bracket;
    
    (i = token_len(node->token), bracket = 0);
    while (--i > -1)
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
    }
    return (FALSE);
}

void branch(t_tree *node, int i)
{
    node->type = node->token[i].type;
    node->token[i].type = 0;

    node->left = create_node();
    node->right = create_node();

    if (node->left)
        node->left->token = &node->token[0];
    if (node->right)
    node->right->token = &node->token[i + 1];
}