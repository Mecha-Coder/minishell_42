#include "../include/minishell.h"
/*
char **get_envp(t_env *current)
{
    int i;
    char **envp;

    i = 0;
    while (current && ++i)
        current = current->next;
    envp = (char **)malloc(i + 1);

    i = 0;
    while (current)
    {
        char *new;
        new = (char *)malloc(strlen(current->key) + strlen(current->val) + 2);
        strcpy(new, current->key);
        strcat(new,"=");
        strcat(new, current->val);
        envp[i++] = new;
        current = current->next;
    }
    envp[i++] = NULL;
    return (envp);
}

void free_list(char **list)
{
    int i;

    i = -1;
    while (list[++i])
        free(list[i]);
    free(list);
}
*/

int descent_tree(t_tree *node, t_env *list)
{
    // char **envp;
    // pid_t pid;

    if (!node)
        return (FALSE);
    if (node->type == CMD)
    {
        if (polish_str_token(node->token, list))
        {
            // prep_exe(node);
            // if (!strcmp(node->cmd[0],"echo"))
            //     builtin_echo(node->cmd);
            // else
            // {
            //     envp = get_envp(list);
            //     pid = fork();
            //     if (pid == 0)
            //         execve("/usr/bin/cat", node->cmd, envp);
            //     else
            //         wait(NULL);
            //     free_list(envp);
            // }
        }
    }
    descent_tree(node->left, list);
    descent_tree(node->right, list);
    return (TRUE);
}

void run_ast(t_shell *data)
{
    data->exit_code = descent_tree(data->tree, data->env);
}

ls | wc | cat 