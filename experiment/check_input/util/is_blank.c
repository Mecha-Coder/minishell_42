#include "../include/minishell.h"

int is_blank(char *s)
{
	while (*s)
	{
		if (!isspace(*s++))
			return (FALSE);
	}
	return(TRUE);
}