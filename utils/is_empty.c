#include "../include/minishell.h"

/* isempty
Purpose: Check string if 
	- 'blank' s[0] = '\0' or 
    - no blank character input "     "
Return  :
    OK  : TRUE
    KO  : FALSE
*/
int is_empty(char *s)
{
	while (s && *s)
	{
		if (!blank_char(*s++))
			return (FALSE);
	}
	return(TRUE);
}