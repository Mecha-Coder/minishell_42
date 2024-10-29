#include "../../../include/minishell.h"

/* after_redirect
Purpose: check redirect token must be followed by <STR>
 2   3   4     5    9
<<   <   >>    >  <STR>
Return
    OK : -1
    KO : redirect operator index in question
*/
void after_redirect(t_shell *data, int *return_index, int *trigger)
{
    int i;

    (i = -1, *trigger = 1);
    while (data->token[++i].type)
    {
        if (data->token[i].type >= HERE && data->token[i].type <= WR
            && data->token[i + 1].type != STR)
        {
            *return_index = data->token[i].index;
            return;
        }
    }
    *return_index = -1;
}
