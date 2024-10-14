#include "include/minishell.h"

static int is_blank(char *s)
{
	while (*s)
	{
		if (!isspace(*s++))
			return (FALSE);
	}
	return(TRUE);
}

static void initialize_data(t_data *data, char *ptr)
{
	data->origin = ptr;
	strcpy(data->s, ptr);
	data->s_len = strlen(ptr);

	/*
	printf("Origin: %s\n" 
		   "Buffer: %s\n"
		   "S_len : %d\n", data->origin, data->s, data->s_len);
	*/
}

int main(int ac, char **av)
{
	t_data data;

	if (ac == 2 && !is_blank(av[1]))
	{
		if (strlen(av[1]) < BUFFER_SIZE)
		{
			initialize_data(&data, av[1]);	
			check_syntax(&data);
		}
		else
			printf("ERROR: Can't process. Input command too long");
    }
	return 0;
}