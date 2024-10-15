#include "../include/token.h"

/* single_and             7
Purpose: Ensure no '&' <XAND> operator as part of the token list
*/

void and(t_data *data, int *return_index)
{
    int i;

    i = -1;
    while (data->token[++i].type != -1)
    {
        if (data->token[i].type == XAND)
        {
            *return_index = data->token[i].index;
            return;
        }    
    }
    *return_index = -1;
}