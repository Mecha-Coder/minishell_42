#include "../include/minishell.h"

static t_env *create_env_node(char *s);
static char *extract_key(char *s, int i);
static char *extract_val(char *s, int i);

/* Test
int main(int ac, char **av, char **env)
{
    t_shell data;
    (void)ac;
    (void)av;

    setup_env(&data, env);
    show_env(&data);
    clear_env(&data);
}
 */

/* setup_env
Purpose: Setup a local env which is a copy of the envp in main(). 
         Store them inside a key/value struct linked-list.
Return
    OK : TRUE
    KO : FALSE (Caused by malloc failure)
*/
int setup_env(t_shell *data, char **env)
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

static t_env *create_env_node(char *s)
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

static char *extract_key(char *s, int i)
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

static char *extract_val(char *s, int i)
{
    char *val;

    s = s + i;
    i = strlen(s);
    val = (char *)malloc(i + 1);
    if (val)
    {
        val[i] = '\0';
        while (--i > -1)
            val[i] = s[i]; 
    }
    return (val);
} 
