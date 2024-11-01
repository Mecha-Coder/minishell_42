#include "../include/minishell.h"

#define IN 0
#define OUT 1

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

int run_pipe(t_tree *node, t_shell *data)
{
    int fd[2];
    int exit_code;

    if (pipe(fd) < 0) 
        return (perror("pipe failed"), EXIT_FAILURE);
    

    node->left->pipe_out = fd;
    node->right->pipe_in = fd;
    if (node->pipe_out)
        node->right->pipe_out = node->pipe_out;

    descent_tree(node->left, data);
    close(fd[1]);
    exit_code = descent_tree(node->right, data);
    close(fd[0]);
    return (exit_code);
}