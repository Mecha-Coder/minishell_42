#include "split.h"

static char *extract_path(char *s, int len, int add_slash);
static char **break_lvl(char *s, int len, char **result);
static char **allocate(char *s, int len);

/* Test 
void show_result(char **result)
{
    int i;

    i = -1;
    while(result[++i])
        printf("%s\n", result[i]);
    printf("\n\n");
    free_list(result);
}

int main()
{
    int i;
    int j;
    int start;
    char *s = "/usr/games:/usr/local/games:/snap/bin:/usr/bin";
    
    (i = -1, start = 0, j = 0);
    while (s[++i])
    {
        if (s[i] == ':' || (s[i + 1] == '\0' && ++j))
        {
            show_result(get_path_lvl(&s[start], i - start + j));
            start = i + 1;
        }
    }    
}
*/

/* path_lvl
Purpose: Break down filepath into each hierarchical directory level.
 
 Input:  /usr/local/sbin
 Output:
    /usr
    /usr/local
    /usr/local/sbin/
                   ↑
  Note: The lst path should end with a "/" (backslash).
 */
char **path_lvl(char *s, int len)
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
    int size;

    (i = -1, size = 0);
    while (i++ < len)
    {
        if (s[i] == '/')
            size++;
    }
    return ((char **)malloc(sizeof(char *) * (size + 1)));
}

static char **break_lvl(char *s, int len, char **result)
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
