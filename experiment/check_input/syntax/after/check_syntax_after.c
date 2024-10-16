#include "../../include/minishell.h"

/* validate
Purpose: Check syntax after tokenize

a) Single '&' shouldn't exist
b) Redirection operator check
c) AND OR & PIPE operator check
d) Bracket check
*/ 

static void indicate_syntax_error(int i, int trigger)
{
    point_index(i);
    if (trigger == 1)      printf("\nSyntax: " RED " ERROR: Found XAND\n" RESET);
    else if (trigger == 2) printf("\nSyntax: " RED " ERROR: Wrong redirect\n" RESET);
    else if (trigger == 3) printf("\nSyntax: " RED " ERROR: Wrong used of operator\n" RESET);
    else if (trigger == 4) printf("\nSyntax: " RED " ERROR: Bracket issue\n" RESET);
}

int check_syntax_after(t_data *data)
{
    int index;
    int trigger;

    if ((after_and(data, &index), trigger = 1, index >= 0)
        || (after_redirect(data, &index), trigger = 2, index >=0)
        || (after_operator(data, &index), trigger = 3, index >=0)
        || (after_bracket(data, &index), trigger = 4, index >=0))
    {
        return(indicate_syntax_error(index, trigger), FALSE);
    }
    return (TRUE);
}