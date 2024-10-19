#include "../include/minishell.h"

void swap_var(char *s, t_env *head)
{
    int i;
    int j;
    int detect = TRUE;
    int var_size;
    char *var_value;

    i= -1;
    while (s[++i])
    {
        if (s[i] == '\'') 
            detect = !detect;
        if (detect && s[i] == '$') // After swap check back at the same spot, don't i++
        {
            j = 0;
            var_size = is_identifier(&s[i + 1]);
            if (var_size > 0)
            {
                var_value = get_value(s[i], var_size, head);
            }
        }
    }
}