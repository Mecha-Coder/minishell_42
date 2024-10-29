#include "../../include/minishell.h"

/* sort_token
Purpose: Sort token based on the index number.
    Index was assigned during poping stage where it was found.
*/
void sort_token(t_shell *data)
{
    int i;
    int swap_count;
    t_token temp;

    swap_count = 1;
    while (swap_count)
    {
        (swap_count = 0, i = 0);
        while (data->token[i + 1].type)
        {
            if (data->token[i].index > data->token[i + 1].index)
            {
                temp = data->token[i + 1];
                data->token[i + 1] = data->token[i];
                data->token[i] = temp;
                swap_count++;
            }
            i++;
        }
    }
}