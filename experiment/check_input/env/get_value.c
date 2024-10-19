#include "../include/minishell.h"

char *get_value(char *s, int size, t_env *head)
{
    t_env *current;
    char key[100];

    if (size > 100)
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

int main(int ac, char **av, char **env)
{
    
}