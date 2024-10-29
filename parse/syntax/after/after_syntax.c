#include "../../../include/minishell.h"

static void show_error(t_shell *data, int index, int trigger);

/* Test
int main()
{
    t_shell data;
    data.input = "echo hello | (cat)";
    data.token[0].type = STR;
    data.token[0].index = 0;
    data.token[0].content = "echo";
    
    data.token[1].type = STR;
    data.token[1].index = 6;
    data.token[1].content = "hello";

    data.token[2].type = PIPE;
    data.token[2].index = 12;

    data.token[3].type = OB;
    data.token[3].index = 14;

    data.token[4].type = STR;
    data.token[4].index = 15;
    data.token[4].content = "cat";

    data.token[5].type = CB;
    data.token[5].index = 18;

    data.token[6].type = -1;
    show_token(&data);
    if (check_syntax_after(&data))
    {
        printf("\n\n%s\n", data.input);
        printf("\nSyntax: " GREEN "OK\n" RESET);
    }
}
 */

/* check_syntax_after
Purpose: Check syntax after tokenize
    - redirect  : Must followed by <STR> token
    - |, &&, || : Check neighbor of operator meet rule
    - Bracket   : Similar check neighbor of bracket meet rule
Return: 
    OK : TRUE
    KO : FALSE
*/
int check_syntax_after(t_shell *data)
{
    int index;
    int trigger;

    if ((after_redirect(data, &index, &trigger), index >= 0)
        || (after_operator(data, &index, &trigger), index >= 0)
        || (after_bracket(data, &index, &trigger), index >= 0))
    {
        return (show_error(data, index, trigger), FALSE);
    }
    return (TRUE);
}

static void show_error(t_shell *data, int index, int trigger)
{
    printf("\n\n%s\n", data->input);
    point_index(index);

    if (trigger == 1)       printf(A_SYN_REDIRECT);
    else if (trigger == 2)  printf(A_SYN_OPERATOR);
    else if (trigger == 3)  printf(A_SYN_BRACKET);
}
 