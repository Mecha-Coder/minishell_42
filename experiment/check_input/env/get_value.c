#include "../include/minishell.h"

char *get_value(char *s, int size, t_env *head)
{
    t_env *current;
    char key[BUFFER_SIZE];

    if (size >= BUFFER_SIZE)
        return (NULL);
    current = head;
    memset(&key, 0, sizeof(key));
    strncpy(key, s, size);
    while (current)
    {
        if (!strcmp(current->key, key))
            return (current->val);
        current = current->next;
    }
    return (NULL);
}

/*
int main(int ac, char **av, char **env)
{
    t_data data;
    char s[] = "HOME";

    (void)ac;
    (void)av;
    create_env(&data, env);
    printf("%.4s = %s\n", s, get_value(s, 4, data.env));
    destroy_env(&data);
}
*/