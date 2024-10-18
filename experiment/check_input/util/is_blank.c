#include "../include/minishell.h"

int is_blank(char *s) // Change to isempty
{
	while (s && *s)
	{
		if (!isspace(*s++))
			return (FALSE);
	}
	return(TRUE);
}