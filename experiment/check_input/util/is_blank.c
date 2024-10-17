#include "../include/minishell.h"

int is_blank(char *s)
{
	while (s && *s)
	{
		if (!isspace(*s++))
			return (FALSE);
	}
	return(TRUE);
}