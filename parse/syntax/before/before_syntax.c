#include "../../../include/minishell.h"

static void show_error(t_shell *data, int index, int trigger);

/* Test - Run with script
int main(int ac, char **av)
{
    t_shell data;
    if (ac == 2 && av[1])
    {
        data.input = av[1];
        strcpy(data.s, av[1]);
        data.s_len = strlen(av[1]);
        if (check_syntax_before(&data))
        {
            printf("\n\n%s\n", data.input);
			printf("\nSyntax: " GREEN "OK\n" RESET);
        }
    }
}
*/

/* check_syntax_before
Purpose: Check the following before tokenize
    - quote   : Single ' and double " must be paired
    - bracket : Open ( & close ) bracket must be paired. Inside can't be empty
    - operator: Check these symbols occurance |, &, <, > 

NOTE: Don't check meta character inside quote pairs

Return: 
    OK : TRUE
    KO : FALSE
*/
int check_syntax_before(t_shell *data)
{
    int index;
    int trigger;

    if ((before_quote(data, &index, &trigger), index >= 0)
        || (before_bracket(data, &index, &trigger), index >= 0)
        || (before_operator(data, &index, &trigger), index >= 0))
    {
        return (show_error(data, index, trigger), FALSE);
    }
    return (TRUE);
}

static void show_error(t_shell *data, int index, int trigger)
{
    printf("\n\n%s\n", data->input);
    point_index(index);

    if (trigger == 1)       printf(B_SYN_QUOTE);
    else if (trigger == 2)  printf(B_SYN_BRACKET);
    else if (trigger == 3)  printf(B_SYN_OPERATOR);
}
 

