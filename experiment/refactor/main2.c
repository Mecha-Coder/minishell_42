#include "include/minishell.h"

int parse(t_shell *data)
{
    if (is_empty(data->input))                return (FALSE);
    if (strlen(data->input) >= BUFFER_SIZE)  return (printf(LONG_INPUT), FALSE);
    
    add_history(data->input);
    strcpy(data->s, data->input);
    data->s_len = strlen(data->s);

    return (check_syntax_before(data)
        && tokenize(data)
        && check_syntax_after(data)
        && build_ast(data));
}

void reset(t_shell *data)
{
    clear_ast(data);
    free_str_token(data);
}

void interective_mode(t_shell *data)
{
    while (1)
    {
        data->input = readline(PROMPT);
        if (data->input)
        {
            if (parse(data))  
            {
                run_ast(data);
                reset(data);
            }
            free(data->input);
        }
        else
        {
            printf(SHUTDOWN);
            break;
        }
    }
}

int main(int ac, char **av, char **env)
{
    t_shell data;

    (void)ac;
    (void)av;
    if (!setup_env(&data, env)) exit(EXIT_FAILURE);

    interective_mode(&data);

    clear_env(&data);
    rl_clear_history();
    return (0);
}