#include "../../include/minishell.h"

int size(char *s);
char **all_path(t_env *list);
char *get_var(char *key, t_env *current);
void parse_path(char *s, char **path);

/* Test
int main()
{
    char **path;
    int i = -1;

    t_env n1;
    t_env n2;
    t_env n3;

    n1.key = "USER";
    n1.val = "jason";
    n1.next = &n2;

    n2.key = "HOME";
    n2.val = "";
    n2.next = &n3;

    n3.key = "PATH";
    n3.val = "/urs/local/bin:/local/sbin:/usr/bin";
    n3.next = NULL;

    path = all_path(&n1);
    while(path[++i])
        printf("%s\n", path[i]);
    
    i = -1;
    while(path[++i])
        free(path[i]);
    free(path);
}
*/

/* all_path
Purpose: Parse $PATH value into individual paths
    
Example: /urs/local/bin:/local/sbin:/usr/bin
    -> /usr/local/bin/
    -> /loca/sbin/
    -> /usr/bin/
Return
    OK: Individual path array
    KO: Not handling (Failed malloc)
        NULL - No path var in env 
*/

char **all_path(t_env *list)
{
    char *s;
    char **allpath;

    s = get_var("PATH", list);
    if (!s)
        return (NULL);
    allpath = (char **)malloc(sizeof(char *) * size(s));
    parse_path(s, allpath);
    return (allpath);
}

int size(char *s)
{
    int i;
    int size;

    (i = -1, size = 2);
    while (s[++i])
    {
        if (s[i] == ':')
            size++;
    }
    return (size);
}