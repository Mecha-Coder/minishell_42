#include "../include/minishell.h"

static t_env *create_env_node(char *key, char *value)
{
    t_env *new;

    new = (t_env *)malloc(sizeof(t_env));
    if (new)
    {
        new->key = key;
        new->val = value;
        new->next = NULL;
    }
    return (new);
}

/*
void view_env(t_env *head)
{
    t_env *current;
    int i = 0;

    current = head;
    while (current)
    {
        printf("%d) %s=%s\n", ++i, current->key, current->val);
        current = current->next;
    }
}
*/

void set_new_env(t_env *head)
{
   t_env *node;

   node = head;
   
   while (node->next)
      node = node->next;

   char *k1 = (char *)malloc(sizeof("_A55"));
   char *k2 = (char *)malloc(sizeof("TEST"));
   char *v1 = (char *)malloc(sizeof("[Done swap]"));
   char *v2 = (char *)malloc(sizeof("in.txt"));
   strcpy(k1,"_A55");
   strcpy(k2,"TEST");
   strcpy(v1,"[Done swap]");
   strcpy(v2,"in.txt");

   node->next = create_env_node(k1, v1);
   node = node->next;
   node->next = create_env_node(k2, v2);
   //view_env(head);
}

void remove_double_quote(char *s)
{
    int i = -1;
    int j;
    int detect = TRUE;

    while (s[++i])
    {
        if (s[i] == '\'') 
            detect = !detect;
        if (detect && s[i] == '\"')
        {
            j = 0;
            while (s[i + j])
            {
                s[i + j] = s[i + j + 1];
                j++;
            }
        }
    }
}

void sub_single_quote(char *s, int sub)
{
    int i;
    int detect = ON;
    char target;
    char replace;

    if (sub)
    {
        target = '\'';
        replace = '#';
    }    
    else
    {
        target = SUB_CHAR;
        replace = '\'';
    }


    i = -1;
    while (s[++i])
    {
        if (detection(s[i], &detect), detect ==  DQ_OFF 
            && s[i] == target)
        {
            s[i] = replace;
        }
    }
}

void run_tree(t_tree *node, t_env *head)
{
    // int exit_status = 10;
    int i;

    i = -1;
    set_new_env(head);
    while (node->token[++i].type != -1)
    {
        if (node->token[i].type == STR)
        {
            sub_single_quote(node->token[i].content, TRUE);
            remove_double_quote(node->token[i].content);
        }
    }
}