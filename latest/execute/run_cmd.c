#include "../include/minishell.h"

void prep_pipe(t_tree *node)
{
    if (node->pipe_in)
    {
        close(node->pipe_in[1]);
        dup2(node->pipe_in[0], STDIN_FILENO);
    }
    
    
    if (node->pipe_out)
    {
        close(node->pipe_out[0]);
        dup2(node->pipe_out[1], STDOUT_FILENO);
    }
    
}

int run_cmd(t_tree *node, t_shell *data)
{
    pid_t id;
    int status;
    
    if (polish_str_token(node->token, data))
    {
        id = fork();
        if (id < 0) return (perror("fork failed"), EXIT_FAILURE);
        else if (!id)
        {
            prep_pipe(node);
            prep_cmd(node);
            none_builtin(node->cmd, data->env);
        }
        else
            waitpid(id, &status, 0);
        return (WEXITSTATUS(status));
    }
    return (EXIT_SUCCESS);
}
