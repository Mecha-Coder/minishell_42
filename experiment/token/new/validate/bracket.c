#include "../include/token.h"

/*
Bracket unpack by stages (())
||  &&

Outside
<START><OPERATOR>  (    ) <OPERATOR><END> 

Inside
              ( <STR> )
            (<OB>   <!CB>) 
            (<!OB>   <CB>)           
*/

#define OB_INDEX 0
#define OB_LEFT 1
#define OB_RIGHT 2
#define CB_INDEX 3
#define CB_LEFT 4
#define CB_RIGHT 5  


int find_bracket_pair(t_token *token, int *bracket, int i, int end)
{
    int count;
    int found;

    (found = FALSE, count = 0, bracket[OB_INDEX] = -1, bracket[CB_INDEX] = -1);
    while(i <= end)
    {
        if (token[i].type == OB && count++)
        {
            if (count == 1 && bracket[OB_INDEX] == -1)
            {
                bracket[OB_INDEX] = i;
                found = TRUE;
            }
        }
        if (token[i].type == CB && count--)
        {
            if (bracket == 0 && bracket[CB_INDEX] == -1)
                bracket[CB_INDEX] = i;
        }
    }
    return (found);
}




int recrusive_bracket(t_token *token, int start, int end)
{
    int bracket[6];
    int result;

    if (find_bracket_pair(token, bracket, start, end))
    {
        result = recrusive_bracket(token, bracket[OB_INDEX] + 1, bracket[OB_INDEX] -1);
        if (result >= 0 )
            return (result);
        else
        {
            result = check_rule(token, bracket, start, end);
            if (result >= 0)
                return (result);
        }       
    }
    return (-1);
}

void bracket(t_data *data, int *return_index)
{
    int i;

    i = 0;
    while (data->token[i].type != -1)
        i++;
    return (recrusive_bracket(data->token, 0, i - 1));
}