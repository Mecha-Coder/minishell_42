#include "../include/minishell.h"

char *swap_var(char *s, t_env *head)
{
    int i;
    int detect = TRUE;
    int var_size;
    char *var_value;
    int malloc = FALSE;
    char *temp;

    i= -1;
    while (s[++i])
    {
        if (s[i] == '\'') 
            detect = !detect;
        if (detect && s[i] == '$') // After swap check back at the same spot, don't i++
        {
            var_size = is_identifier(&s[i + 1]);
            if (var_size)
            {
                var_value = get_value(&s[i + 1], var_size, head);
                if (var_value)
                {
                    s[i] = '\0';
                    temp = special_join(s, var_value, &s[i + var_size + 1]);
                    if (malloc)
                        free(s);
                    s = temp;
                    malloc = TRUE;           
                }
                else
                    trim_off(&s[i], var_size + 1);
            }
        }
    }
    if (malloc)
        return (s);
    return (NULL);
}

/*
int main(int ac, char **av, char **env)
{
    t_data data;
    char s[] = "[Path $SHELL  ' $SHELL ' && XX]";
    char *ptr;

    (void)ac;
    (void)av;
    create_env(&data, env);
    ptr = swap_var(s, data.env);
    
    if (ptr)
    {
        printf("%s\n", ptr);
        free(ptr);
    }
    else
        printf("%s\n", s);

    
    destroy_env(&data);
    return 0;
}
*/