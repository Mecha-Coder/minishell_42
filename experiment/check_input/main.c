#include "include/minishell.h"

static void initialize_data(t_data *data, char *s)
{
	data->origin = s;
	strcpy(data->s, s);
	data->s_len = strlen(s);
}

int main(int ac, char **av, char **env)
{
	t_data data;

	create_env(&data, env);

	if (ac == 2 && !is_blank(av[1]))
	{
		if (strlen(av[1]) < BUFFER_SIZE)
		{
			initialize_data(&data, av[1]);
			if (check_syntax_before(&data) 
				&& tokenize(&data)
				&& check_syntax_after(&data))
			{
				printf("\n\n%s\n", data.origin);
				printf("\nSyntax: " GREEN "OK\n" RESET);

				data.root = create_node();
    			data.root->token = data.token;
				build_tree(data.root);
				run_tree(data.root, data.env);
				printf("\n");
				visualize_tree(data.root, 0);
				printf("\n");
				destroy_tree(data.root);
			}
		}
		else
			printf("ERROR: Can't process. Input command too large\n");
	}
	destroy_env(&data);
	return 0;
}