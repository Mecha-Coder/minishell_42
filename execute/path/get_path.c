#include "../../include/minishell.h"

/* get_path
Purpose: Check if given string is a valid executable path
    Else, concat file with each env path and check it's valid executable
Return 
    NULL : Not a valid path or no executable in env with that name
    OK   : Path string (Must malloc consistency)
*/
char *get_path(char *s, t_env *list)
{
    int i;
    char **all;
    char *path;

    i = -1;
    path = join_str(NULL, s);
    if (!access(path, F_OK | X_OK))
        return (path);
    free(path);

    all = all_path(list);
    while(all && all[++i])
    {
        path = join_str(all[i], s);
        if (!access(path, F_OK | X_OK))
            break;
        free(path);
        path = NULL;
    }
    free_list(all);
    return (path);
}