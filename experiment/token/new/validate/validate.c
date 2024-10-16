#include "../include/token.h"

/* validate
Purpose: Check syntax after tokenize

a) Single '&' shouldn't exist
b) Redirection operator check
c) AND OR & PIPE operator check
d) Bracket check
*/ 

void indicate_syntax_error(int i, int trigger)
{
    point_index(i);
    if (trigger == 1)
        printf("\nSyntax: " RED " ERROR: Found XAND\n" RESET);
    else if (trigger == 2)
        printf("\nSyntax: " RED " ERROR: Wrong redirect\n" RESET);
    else if (trigger == 3)
        printf("\nSyntax: " RED " ERROR: Wrong used of operator\n" RESET);
    else if (trigger == 4)
        printf("\nSyntax: " RED " ERROR: Bracket issue\n" RESET);
}

int validate(t_data *data)
{
    int index;
    int trigger;

    printf("\n%s\n", data->origin);

    if ((and(data, &index), trigger = 1, index >= 0)
        || (redirect(data, &index), trigger = 2, index >=0)
        || (operator(data, &index), trigger = 3, index >=0)
        || (bracket(data, &index), trigger = 4, index >=0))
    {
        return(indicate_syntax_error(index, trigger), FALSE);
    }
        
    printf("\nSyntax: " GREEN "OK\n" RESET);
    return (TRUE);
    
}