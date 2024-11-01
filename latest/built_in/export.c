#include "../include/minishell.h"

/* Test */
int answer()
{
  
}

int main()
{
    t_shell data;
    setup_env(&data, env);

    // OK
    char *a1[] = {"export", "TEST=test", NULL};
    char *a2[] = {"export", "TEST=test user", NULL};                
    char *a3[] = {"export", "TEST=ici=coucou", NULL};
    char *a6[] = {"export", "TEST", NULL}; // Do nothing (ignore)
    char *a6[] = {"export", "$DDD", NULL}; // Do nothing (ignore)                   
    char *a4[] = {"export", "TEST="};
    char *a5[] = {"export", "_A55==Rolling+", NULL}; 
    char *a7[] = {"export", "VAR", NULL};  

    //ERROR
    char *a8[] = {"export", "VAR", "=", "Hello", NULL};                   
    char *a9[] = {"export", "55@=Time", NULL};                
                    
    (void)ac;
    (void)av;
      
    show_env(&data);
    destroy_env(&data);
}

/* export
Purpose: Check if key is valid identifier.
    If key exist, amend value
    Els,  Add new variable (key/val pair) into the env
Return:
    OK: Amend or add new variable
    KO: Not a valid identifier

Note: To reflect changes must not be in fork()
*/
export (char **cmd, t_env *list)