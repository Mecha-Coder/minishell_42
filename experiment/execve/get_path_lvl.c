#include "split.h"

static char *extract_path(char *s, int len, int add_slash);
static char **break_lvl(char *s, int len, char **result);
static char **allocate(char *s, int len);

/* Test
int main()
{
    char *s = "/usr/games:/usr/local/games:/snap/bin";
    char **result;
    int i = -1;

    result = get_path_lvl(&s[10 + 1], 15);
    while(result[++i])
        printf("%s\n", result[i]);
    free_list(result);
}
*/

/* get_path_lvl
Purpose: Break down file path into each hierarchical directory level.
 
 Input:  /usr/local/sbin
 Output:
    /usr
    /usr/local
    /usr/local/sbin/
                   ↑
  Note: The lst path should end with a "/" (backslash).
 */
char **get_path_lvl(char *s, int len)
{
    char **result;
    result = allocate(s, len);
    if (result)
        result = break_lvl(s, len, result);
    return (result);
}

static char **allocate(char *s, int len)
{
    int i;
    int slot;

    (i = -1, slot = 0);
    while (i++ < len)
    {
        if (s[i] == '/')
            slot++;
    }
    return ((char **)malloc(sizeof(char *) * (slot + 1)));
}

static char  **break_lvl(char *s, int len, char **result)
{
    int i;
    int j;
    char *temp;

    (i = 0, j = 0);
    while(++i < len)
    {
        if (s[i] == '/')
        {
            temp = extract_path(s, i, FALSE);
            if (temp)
                result[j++] = temp;
            else
                return (free_list(result), NULL);
        }
    }
    temp = extract_path(s, len, TRUE);
    if (temp)
        result[j++] = temp;
    else
        return (free_list(result), NULL);
    result[j] = NULL;
    return (result);
}

static char *extract_path(char *s, int len, int add_slash)
{
    int i;
    int total;
    char *new;

    (i = -1, total = len + 1);
    if (add_slash)
        total++;
    new = (char *)malloc(total);
    if (new)
    {
        while (++i < len)
            new[i] = s[i];
        if (add_slash)
            new[i++] = '/';
        new[i] = '\0';
    }
    return (new);
}
