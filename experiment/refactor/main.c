#include "include/minishell.h"

int start(t_shell *data, char **env);
int parse(t_shell *data, int ac, char **av);
void end(t_shell *data);


/* Main
Purpose: Act as startpoint when readline receive input
*/
int main(int ac, char **av, char **env)
{
    // When launching minishell program
    t_shell data;

    if (!start(&data, env)) exit(EXIT_FAILURE);

    // ------------------------------------------------------------------------
    // When receive input from realine

    (parse(&data, ac, av) && execute(&data));

    // Execute input and reset for next command




    // ------------------------------------------------------------------------
    // Shutting down minishell program

    end(&data);
}


int start(t_shell *data, char **env)
{
    return (setup_env(&data, env));
}

int parse(t_shell *data, int ac, char **av)
{
    if (ac != 2 || isempty(av[1]))     return (FALSE);
    if (strlen(av[1]) >= BUFFER_SIZE)  return (printf(LONG_INPUT), FALSE);
    
    data->input = av[1];
    strcpy(data->s, av[1]);
    data->s_len = strlen(av[1]);

    return (check_syntax_before(&data)
        && tokenize(&data)
        && check_syntax_after(&data)
        && build_tree(&data));
}

void end(t_shell *data)
{
    clear_env(&data);
}