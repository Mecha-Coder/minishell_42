#include "../../include/minishell.h"

static void initialize_data(t_shell *data, char *s)
{
	data->input = s;
	strcpy(data->s, s);
	data->s_len = strlen(s);
}

int main(int ac, char **av)
{
    t_shell data;

    if (ac == 2 && !isempty(av[1]))
	{
		if (strlen(av[1]) < BUFFER_SIZE)
		{
			initialize_data(&data, av[1]);
            if (check_syntax_before(&data) && printf("[B:OK]\n")
				&& tokenize(&data) && show_token(&data)
				&& check_syntax_after(&data))
			{
				printf("\n\n%s\n", data.input);
				printf("\nSyntax: " GREEN "OK\n" RESET);
            }
        }       
    }
}

