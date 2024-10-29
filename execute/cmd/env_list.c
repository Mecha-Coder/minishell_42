#include "../../include/minishell.h"

/* env_list
Purpose: Convert the local environment stored in a sturcr 
    into a 2D array
Param: 
    linked-list "head" of the env struct
Return:
    OK : local env in 2D array form
    KO : Not handling (Failed malloc) 
*/
char **env_list(t_env *current)
{
    int i;
    int total;
    char **list;
    char *s;

    i = 0;
    while (current && ++i)
        current = current->next;
    list = (char **)malloc(i + 1);

    i = 0;
    while (current)
    {
        total = strlen(current->key) + strlen(current->val) + 2;
        s = (char *)malloc(total);
        strcpy(s, current->key);
        strcat(s,"=");
        strcat(s, current->val);
        list[i++] = s;
        current = current->next;
    }
    list[i++] = NULL;
    return (list);
}
