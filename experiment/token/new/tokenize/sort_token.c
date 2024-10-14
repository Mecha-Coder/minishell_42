#include "../include/token.h"

void sort_token(t_data *data)
{
    int i;
    int swap_count;
    t_token temp;

    swap_count = 1;
    while (swap_count)
    {
        (swap_count = 0, i = 0);
        while (data->token[i + 1].type >= 0)
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