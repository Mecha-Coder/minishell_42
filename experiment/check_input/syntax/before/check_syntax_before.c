#include "../../include/minishell.h"

/* syntax_error_check
1) check_quote: Single (') and double (") must be paired
2) check_bracket: Bracket "(" ")" must be pair in this arrangement. Inside can't be empty 
3) check_operator: Check operator occurance
4) check_arrangement: Token arrangement must follow rule    
	
NOTE: Do not count or check meta character when inside quotes pair
*/

void indicate_syntax_error(int i, int trigger)
{
	point_index(i);
    if (trigger == 1)      printf("\nSyntax: " RED " ERROR: Quote not in pair\n" RESET);
    else if (trigger == 2) printf("\nSyntax: " RED " ERROR: Bracket placement issue\n" RESET);
    else if (trigger == 3) printf("\nSyntax: " RED " ERROR: Invalid operator\n" RESET);
}

int check_syntax_before(t_data *data)
{
	int index;
	int trigger;

	if ((before_quote(data, &index), trigger = 1, index >= 0)
        || (before_bracket(data, &index), trigger = 2, index >= 0)
        || (before_operator(data, &index), trigger =3 ,index >=0))
	{
		printf("\n\n%s\n", data->origin);
		return (indicate_syntax_error(index, trigger), FALSE);
	}
	return (TRUE);
}