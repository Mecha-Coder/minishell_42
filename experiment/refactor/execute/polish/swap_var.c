#include "../../include/minishell.h"

char *insert_var(char *s, int i, int *len, t_env *list);

/* Test

int main(int ac, char **av, char **env)
{
    t_shell data;
    char s[] = "[Path $TEST  \" $SHELL \" && XX]";
    char *ptr;

    (void)ac;
    (void)av;
    setup_env(&data, env);
    ptr = swap_var(s, data.env);
    
    if (ptr)
    {
        printf("%s\n", ptr);
        free(ptr);
    }
    else printf("Failed\n");
    clear_env(&data);
    return 0;
}
*/

/* swap_var
Purpose: Insert variable ($----) value into the string. 
Result: 
    string: Sucessfully swap
    NULL  : Failed malloc
*/
char *swap_var(char *s, t_env *list)
{
    int i;
    int detect;
    int len;
    int malloc_status;
    char *temp;

    (i = -1, detect = TRUE, malloc_status = FALSE);
    while (s && s[++i])
    {
        if (s[i] == '\'')
            detect = !detect;
        if (detect && s[i] == '$' && is_identifier(&s[i + 1], &len))
        {
            temp = insert_var(s, i, &len, list);
            if (malloc_status)
                free(s);
            s = temp;
            malloc_status = TRUE;
            i += len - 1; 
        }
    }
    return (s);
}

char *insert_var(char *s, int i, int *len, t_env *list)
{
    char *var_value;
    char *result;

    s[i] = '\0';
    var_value = get_value(&s[i + 1], *len, list);
    result = join3(s, var_value, &s[i + *len + 1]);
    if (var_value)
        *len = strlen(var_value);
    else
        *len = 0;
    return (result);
}