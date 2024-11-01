#include "../include/minishell.h"

/* Test */
int answer()
{
  
}
/* Jason*/
int main()
{
    t_shell data;

    t_env n1;
    t_env n2;
    t_env n3;

    n1.key = "HOME";
    n1.val = "/home/jpaul";
    n1.next = &n2;

    n2.key = "USER";
    n2.val = "Jason";
    n2.next = &n3;

    n3.key = "SHELL";
    n3.val = "/bash/";
    n3.next = NULL;

    data.env = &n1;

    // OK
    char *a0[] = {"export"};                                                    // Export without arg
    char *a1[] = {"export", "TEST=test", NULL};                                 // Show list
    char *a1[] = {"export", "TEST=test", NULL};                                 // Normal
    char *a2[] = {"export", "TEST=test user", NULL};                            // Space inside val             
    char *a3[] = {"export", "TEST=ici=coucou", NULL};                           // Val have =
    char *a6[] = {"export", "TEST", NULL};                                      // Only var that is in env
    char *a6[] = {"export", "$DDD", NULL};                                      // Only invalid var           
    char *a4[] = {"export", "TEST="};                                           // Only var + =
    char *a4[] = {"export", "=Yoyo"};                                           // Nameless var 
    char *a5[] = {"export", "_A55==Rolling+", NULL};                            // Var with underscore & digit
    char *a7[] = {"export", "VAR", NULL};                                       // Only var not in env
    char *a7[] = {"export", "AI=haha", "BI=yoyo", "TEST=change please",NULL};   // Multiple argument

    // ERROR
    char *a8[] = {"export", "VAR", "=", "Hello", NULL};                         // Invalid indentifier             
    char *a9[] = {"export", "55@=Time", NULL};                                  // Invalid indentifier 
                    
}

/* export
Purpose: 
    1) Export without arg, display in accending ASCII order
    1) Check if key is valid identifier.
    If key exist, amend value
    Els,  Add new variable (key/val pair) into the env

Return:


Error message:

Note: To reflect changes must not be in fork()
*/
export (char **cmd, t_env *list)