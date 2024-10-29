#include "../../../include/minishell.h"

#define OB_INDEX 0
#define OB_LEFT 1
#define OB_RIGHT 2
#define CB_INDEX 3
#define CB_LEFT 4
#define CB_RIGHT 5 

static int eval_bracket(t_token *token, int start, int end);
static int find_bracket_pair(t_token *token, int *bracket, int i, int end);
static int check_rule(t_token *token, int *bracket, int  start, int end);
static void determine_neighbor(t_token *token, int *bracket, int  start, int end);

/* after_operator
Purpose: Check bracket pairs follow below rule. (start with outmost) 
    If available, proceed with inner bracket pairs recursively and check same rule.
    After done, move forward and validate other bracket groups/pairs.

Outside
<START><AND><OR> (    ) <AND><OR><END> 

Inside
( <STR> )  OR 
(<OB>   <!CB>)  OR 
(<!OB>   <CB>)           
*/
void after_bracket(t_shell *data, int *return_index, int *trigger)
{
    int i;
    int count;
    int start;
    int result;

    (i = -1, count = 0, start = 0, *trigger = 3);
    while (data->token[++i].type)
    {
        if (data->token[i].type == OB) 
            count++;
        if (data->token[i].type == CB && !(--count))
        {
            result = eval_bracket(data->token, start, i + 1);
            if (result >= 0)
            {
                *return_index = data->token[result].index;
                return;
            }
            start = i + 1;
        }
    }
    *return_index = -1;
}

static int eval_bracket(t_token *token, int start, int end)
{
    int bracket[6];
    int result;
    
    if (start < end && find_bracket_pair(token, bracket, start, end))
    {   
        result = check_rule(token, bracket, start, end);
        if (result >= 0)
            return (result);
        return (eval_bracket(token, bracket[OB_INDEX] + 1, bracket[CB_INDEX] -1));
    }
    return (-1);
}

static int find_bracket_pair(t_token *token, int *bracket, int i, int end)
{
    int count;

    (count = 0, bracket[OB_INDEX] = -1, bracket[CB_INDEX] = -1);
    while(i <= end)
    {   
        if (token[i].type == OB && ++count 
            && count == 1 && bracket[OB_INDEX] == -1)
        {
            bracket[OB_INDEX] = i;
        }
        if (token[i].type == CB && !(--count)
            && bracket[CB_INDEX] == -1)
        {
            bracket[CB_INDEX] = i;
            return (TRUE);
        }
        i++;
    }
    return (FALSE);
}

static int check_rule(t_token *token, int *bracket, int  start, int end)
{
    determine_neighbor(token, bracket, start, end);
    
    if (bracket[OB_LEFT] != 0 
        && bracket[OB_LEFT] != OR 
        && bracket[OB_LEFT] != AND)
    {
        return (bracket[OB_INDEX]);
    }
    if (bracket[CB_RIGHT] != 0
        &&  bracket[CB_RIGHT] != OR 
        &&  bracket[CB_RIGHT] != AND)
    {
        return (bracket[CB_INDEX]);
    }
    if (bracket[OB_RIGHT] == OB  && bracket[CB_LEFT] == CB)
        return (bracket[OB_INDEX]);
    return (-1);
}

static void determine_neighbor(t_token *token, int *bracket, int  start, int end)
{
    if (bracket[OB_INDEX] == start)
        bracket[OB_LEFT] = 0;
    else
        bracket[OB_LEFT] = token[bracket[OB_INDEX] - 1].type;
    
    if (bracket[CB_INDEX] == end)
        bracket[CB_RIGHT] = 0;
    else 
        bracket[CB_RIGHT] = token[bracket[CB_INDEX] + 1].type;
   
    bracket[CB_LEFT]  = token[bracket[CB_INDEX] - 1].type;
    bracket[OB_RIGHT] = token[bracket[OB_INDEX] + 1].type;
}