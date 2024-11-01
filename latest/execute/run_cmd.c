#include "../include/minishell.h"



int run_cmd(t_tree *node, t_shell *data)
{
    // pid_t id;
    // int status;
    
    if (polish_str_token(node->token, data))
    {
        prep_cmd(node);



        if (!strcmp(node->cmd[0], "cd"))
            builtin_cd(node->cmd, data);
        else if (!strcmp(node->cmd[0], "pwd"))
            builtin_pwd();









        // id = fork();
        // if (id < 0) return (perror("fork failed"), EXIT_FAILURE);
        // else if (!id)
        // {
        //     prep_pipe(node);
        //     none_builtin(node->cmd, data->env);
        // }
        // else
        //     waitpid(id, &status, 0);
        // return (WEXITSTATUS(status));
    }
    return (EXIT_SUCCESS);
}
