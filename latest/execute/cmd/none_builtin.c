#include "../../include/minishell.h"

void	child(char **cmd, t_env *list);

/* none_builtin
Purpose: Execute command that is not part of the builtin
*/
int none_builtin(t_tree *node, t_env *list)
{
    pid_t id;
    int status;

    id = fork();
    if (id < 0) {perror("fork failed"); exit(EXIT_FAILURE);}
    else if (!id)
        child(node->cmd, list);
    else
        waitpid(id, &status, 0);
    return (WEXITSTATUS(status));
}

void	child(char **cmd, t_env *list)
{
    char **env;
	char *path;

	path = get_path(cmd[0], list);
	if (!path)
	{
		printf("%s: command not found\n", cmd[0]);
        exit(127);
	}
    env = env_list(list);
	if (execve(path, cmd, env) < 0)
    {
        free_list(env);
	    free(path);
        printf("Fail execution");
	    exit(EXIT_FAILURE);
    }
	
}