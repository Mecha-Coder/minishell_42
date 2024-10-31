#include "../../include/minishell.h"

char *insert_var(char *s, int i, int *len, t_env *list);
char *insert_exit_code(char *s, int i, int *len, int code);
void convert_num(char *str, int code);
void int_to_str(char *str, int code, int *i);


/* Test

int main(int ac, char **av, char **env)
{
    t_shell data;
    char s[] = "[Path $TEST  \" $SHELL \" $?$$$USER]";
    char *ptr;

    (void)ac;
    (void)av;
    setup_env(&data, env);
    data.exit_code = 0;
    printf("Enter1\n");
    ptr = swap_var(s, &data);
    printf("Enter2\n");

    if (ptr)
    {
        printf("%s\n", ptr);
        free(ptr);
    }
    else printf("Failed\n");
    destroy_env(&data);
    return 0;
}
*/

/* swap_var
Purpose: Insert variable ($----) value into the string. 
Result: 
    string: Sucessfully swap
    NULL  : Failed malloc
*/
char *swap_var(char *s, t_shell *data)
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
        if (detect && s[i] == '$'
            && (is_identifier(&s[i + 1], &len) || s[i + 1] == '?'))
        {
            if (is_identifier(&s[i + 1], &len))
                temp = insert_var(s, i, &len, data->env);
            
            if (s[i + 1] == '?')
            {
                len = 1;
                temp = insert_exit_code(s, i, &len, data->exit_code);
            }
                
            
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

char *insert_exit_code(char *s, int i, int *len, int code)
{
    char str[4];
    char *result;
    
    s[i] = '\0';
    convert_num(str, code);
    result = join3(s, str, &s[i + *len + 1]);
    *len = strlen(str);
    return (result);
}

void convert_num(char *str, int code)
{
    int i;

    if (code == 0) 
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    i = 0;
    int_to_str(str, code, &i);
    str[i] = '\0';
}

void int_to_str(char *str, int code, int *i)
{
    if (code == 0)
        return;
    int_to_str(str, code / 10, i);
    str[(*i)++] = (code % 10) + '0';
}
