#include "../../../include/minishell.h"

/* after_operator
Purpose: Check these operator left & right side below rule 
||  |  &&  

Left side  : <CB><!START><STR>
Right right: <OB><!END><STR>
*/
void after_operator(t_shell *data, int *return_index, int *trigger)
{
    int i;

    (i = -1, *trigger = 2);
    while (data->token[++i].type)
    {   
        if (data->token[i].type == OR 
            || data->token[i].type == PIPE
            || data->token[i].type == AND)
        {
            if (i == 0 || !data->token[i + 1].type
                || (data->token[i + 1].type != OB && data->token[i + 1].type != STR)
                || (data->token[i - 1].type != CB && data->token[i - 1].type != STR))
            {
                *return_index = data->token[i].index;
                return;
            }
        }
    }
    *return_index = -1;
}