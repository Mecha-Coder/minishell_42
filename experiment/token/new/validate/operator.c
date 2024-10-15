#include "../include/token.h"

/* operator
Purpose: Check these operator left & right side 
 0  1   6
||  |  &&  

For left:
    <CB><!START><STR>
For right:
    <OB><!END><STR>
*/
void operator(t_data *data, int *return_index)
{
    int i;

    i = -1;
    while (data->token[++i].type != -1)
    {   
        
        if (data->token[i].type == OR 
            || data->token[i].type == PIPE
            || data->token[i].type == AND)
        {
            if (i == 0 
                ||  data->token[i + 1].type == -1
                || (data->token[i + 1].type != OB 
                &&  data->token[i + 1].type != STR)
                || (data->token[i - 1].type != CB 
                &&  data->token[i - 1].type != STR))
            {
                *return_index = data->token[i].index;
                return;
            }
        }
    }
    *return_index = -1;
}