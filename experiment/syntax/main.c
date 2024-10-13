#include "syntax.h"

/* syntax_error_check
1) check_quote: Single (') and double (") must be paired
2) check_bracket: Bracket "(" ")" must be pair in this arrangement. Inside can't be empty 
3) check_operator: Check operator occurance
4) check_arrangement: Token arrangement must follow rule    
	
NOTE: Do not count or check meta character when inside quotes pair
*/

void highlight_issue(int index)
{
	int i;

	i = 0;
	while(i++ < index)
		printf(" ");
	printf("↑\n");
}

void syntax_error_check(char *s)
{
	int index;

	printf("\n%s\n", s);
	if ((check_quote(s, &index), index >= 0)
        || (check_bracket(s, &index), index >= 0)
        || (check_operator(s, &index), index >=0)
        || (check_arrangement(s, &index), index >=0)
    )
	{
		highlight_issue(index);
		printf("\nSyntax: " RED " ERROR\n" RESET);
	}
	else
		printf("\nSyntax: " GREEN "OK\n" RESET);
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1] && av[1][0])
		syntax_error_check(av[1]);
	return 0;
}