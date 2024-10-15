#include "../include/token.h"

/* redirect
Purpose: Redirect token must be followed by <STR>
 2   3   4     5    10
<<   <   >>    >  <STR>
*/
void redirect(t_data *data, int *return_index)
{
    int i;

    i = -1;
    while (data->token[++i].type != -1)
    {
        if (data->token[i].type >= HERE 
            && data->token[i].type <= WR
            && data->token[i + 1].type != STR)
        {
            *return_index = data->token[i].index;
            return;
        }
    }
    *return_index = -1;
}

