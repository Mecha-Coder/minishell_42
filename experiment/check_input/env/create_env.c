#include "../include/minishell.h"

//1 2 3 4 5 6 7 8 9 10
//0 1 2 3 4 5 6 7 8 9
//T E S T = h a h a h

//1 2 3 4 5 6 7 8 9 10
//0 1 2 3 4 5 6 7 8 9
//T E S T =

char *extract_key(char *s, int i)
{
    char *key;

    key = (char *)malloc(i + 1);
    if (key)
    {
        key[i] = '\0';
        while (--i > -1)
            key[i] = s[i]; 
    }
    return (key); 
}

char *extract_val(char *s, int i)
{
    char *val;

    s = s + i;
    i = 0;
    while (s[i])
        i++;
    val = (char *)malloc(i + 1);
    if (val)
    {
        val[i] = '\0';
        while (--i > -1)
            val[i] = s[i]; 
    }
    return (val);

} 

t_env *create_env_node(char *s)
{
    t_env *new;
    int i;

    i = 0;
    new = (t_env *)malloc(sizeof(t_env));
    if (new)
    {
        while (s && s[i] != '=')
            i++;
        new->key = extract_key(s, i);
        new->val = extract_val(s, i + 1);
        new->next = NULL;
    }
    return (new);
}

int create_env(t_data *data, char **env)
{
    int i;
    t_env *current;

    i = 0;
    data->env = create_env_node(env[i]); 
    current = data->env;
    while (env[++i])
    {
        if (!current)
            return (FALSE);
        current->next = create_env_node(env[i]);
        current = current->next;
    }
    return (TRUE);
}

/*
int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    create_env(&data, env);
    view_env(&data);
    destroy_env(&data);
    return 0;
}
*/
