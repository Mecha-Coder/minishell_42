#include "split.h"

int	get_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}