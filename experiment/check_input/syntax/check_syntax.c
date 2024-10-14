#include "../include/minishell.h"

/* syntax_error_check
1) check_quote: Single (') and double (") must be paired
2) check_bracket: Bracket "(" ")" must be pair in this arrangement. Inside can't be empty 
3) check_operator: Check operator occurance
4) check_arrangement: Token arrangement must follow rule    
	
NOTE: Do not count or check meta character when inside quotes pair
*/

void indicate_syntax_error(int i)
{
    point_index(i);
	printf("\nSyntax: " RED " ERROR\n" RESET);
}

int check_syntax(t_data *data)
{
	int index;

    printf("\n%s\n", data->origin);

	if ((quote(data, &index), index >= 0) 
        || (bracket(data, &index), index >= 0))
        return (indicate_syntax_error(index), FALSE);
    
    if (tokenize(&data))
        return (printf("ERROR: Can't process. Command too long"), FALSE);
    
    if ((operator(data, &index), index >=0)
        || (arrangement(data, &index), index >=0))
        return (indicate_syntax_error(index), FALSE);
	
	printf("\nSyntax: " GREEN "OK\n" RESET);
    return (TRUE);    
}