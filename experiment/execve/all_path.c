#include "split.h"

static char *get_path_var(char **env);
static char **join_path(char **list1, char **list2);
static int listlen(char **list);

/*Test
int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    char **path;
    int i;

    i = -1;
    path = get_path(env);
    while(path[++i])
        printf("%s\n", path[i]);
    free_list(path);
    return (0);
}
*/

/* all_path
Purpose: Generate a list of paths where the executable maybe located
    Need to parse env variable $PATH
 
 Input:  /usr/games:/usr/local/games:/snap/bin
 Output:
    /usr
    /usr/game/
    /usr
    /usr/local
    /usr/local/games/
    /snap
    /snap/bin/
 */
char **all_path(char **env)
{
    int i;
    int j;
    int start;
    char *s;
    char **answer;
    char **temp;

    (i = -1, start = 0, answer = NULL, j = 0);
    s = get_path_var(env);
    
    while (s[++i])
    {
        if (s[i] == ':' || (s[i + 1] == '\0' && ++j))
        {
            temp = path_lvl(&s[start], i - start + j);
            if (!temp)
                return (free_list(answer), NULL);
            answer = join_path(answer, temp);
            if (!answer)
                return (NULL);
            start = i + 1;
        }
    }
    return (answer);
}

static char *get_path_var(char **env)
{
    int i;

    i = -1;
    while (env[++i])
    {
        if(!strncmp(env[i], "PATH=", 5))
            return (env[i] + 5);
    }
    return (NULL);

}

static char **join_path(char **list1, char **list2)
{
    int i;
    int j;
    int total;
    char **new;

    i = 0;
    total = listlen(list1) + listlen(list2) + 1;
    new = (char **)malloc(sizeof(char *) * total);
    if (new)
    {
        j = 0;
        while(list1 && list1[j])
            new[i++] = list1[j++];
        j = 0;
        while(list2 && list2[j])
            new[i++] = list2[j++];
        new[i] = NULL;
    }
    if (list1)
        free(list1);
    if (list2)
        free(list2);
    return (new);
}

static int listlen(char **list)
{
    int i;

    i = 0;
    while (list && list[i])
        i++;
    return(i);
}

