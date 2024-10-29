#include "../include/minishell.h"

/*Test
int main()
{
    char *result;
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

    result = get_var("PATH", &n1);
    if (result)
        printf("%s\n", result);
    else
        printf("NULL values\n");
}
*/

/* get_var
Purpose: Get the value of a variable in local env
Return
    OK : $PATH string value
    KO : NULL - $PATH not available/deleted
         NULL - blank
*/
char *get_var(char *key, t_env *current)
{
    while(current && strcmp(current->key, key))
        current = current->next;
    if (current && current->val[0])
        return (current->val);
    return (NULL);
}