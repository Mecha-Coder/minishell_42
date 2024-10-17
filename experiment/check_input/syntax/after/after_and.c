#include "../../include/minishell.h"

/* no_and
Purpose: Ensure no '&' <XAND> operator as part of the token list
*/
void after_and(t_data *data, int *return_index)
{
    int i;

    i = 0;
    while (data->token[i].type != -1 && data->token[i].type != XAND)
        i++;
    if (data->token[i].type == XAND)
        *return_index = data->token[i].index;
    else
        (*return_index = -1, printf("[A1:OK]"));
}