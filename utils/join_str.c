#include "../include/minishell.h"

static int get_len(char *s)
{
	int i;

	i = 0;
	while (s && *s++)
		i++;
	return (i);
}

char	*join_str(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(get_len(s1) + get_len(s2) + 1);
	if (ptr)
	{
		while (s1 && *s1)
			ptr[i++] = *s1++;
		while (s2 && *s2)
			ptr[i++] = *s2++;
		ptr[i] = '\0';
		return (ptr);
	}
	return (ptr);
}