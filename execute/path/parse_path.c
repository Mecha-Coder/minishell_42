#include "../../include/minishell.h"

char *extract_path(char *s, int len);

/* Test
int main()
{
    char **path;
    char *s = "/urs/local/bin:/local/sbin:/usr/bin";
    int i;

    i = -1;
    path = (char **)malloc(sizeof(char *) * 4);
    parse_path(s, path);

    while(path[++i])
        printf("%s\n", path[i]);
    
    i = -1;
    while(path[++i])
        free(path[i]);
    free(path);
}
*/

/* break_path
Purpose: split into individual paths
    
Example: /urs/local/bin:/local/sbin:/usr/bin
    -> /usr/local/bin/
    -> /loca/sbin/
    -> /usr/bin/
*/

void parse_path(char *s, char **path)
{
    int i;
    int j;
    int k;
    int start;

    (i = -1, k = 0, j = 0, start = 0);
    while (s[++i])
    {
        if (s[i] == ':' || (s[i + 1] == '\0' && ++j))
        {
            path[k++] = extract_path(&s[start], i - start + j);
            start = i + 1;
        }
    }
    path[k] = NULL;
}

char *extract_path(char *s, int len)
{
    int i;
    char *str;

    i = -1;
    str = (char *)malloc(len + 2);
    while (++i < len)
        str[i] = s[i];
    str[i++] = '/';
    str[i] = '\0';
    return (str);
}
