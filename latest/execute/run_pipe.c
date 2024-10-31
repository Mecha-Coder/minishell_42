#include "../include/minishell.h"

#define IN 0
#define OUT 1

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