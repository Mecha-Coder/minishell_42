#include "../include/token.h"

/*
Bracket unpack by stages (())

||  &&

Outside
<START><OPERATOR>  (    )  <OPERATOR><END> 

Inside
            (<OB>   <!CB>) 
            (<!OB>   <CB>)           

OK
echo hello && (echo) && echo hi  ✅
echo hello && (echo nice && ls) && echo hi ✅
echo hello && (echo nice && (ls)) && echo hi ❌
(echo hello) ✅
echo hello | (cat) ❌
(ls) ✅

echo hello && (echo hi && (echo good && echo day))

ls && (ls && (ls && (ls && (ls && (ls && (ls)))))) && ls

ERROR
((echo hello))
echo hello && (echo (nice)) && echo hi ❌
echo hello && () && echo hi ❌
echo hello && (echo nice (ls)) && echo hi ❌
echo hello && ((echo nice && (ls))) && echo hi
*/

void bracket(t_data *data, int *return_index)
{
    int i;
    int bracket;
    int left;
    int right;
    
    (i = -1, left = -1, right = -1, bracket = 0);

    while(data->token[++i].type != -1)
    {
        if (data->token[i].type == OB)
        {
            bracket++;
            if (bracket == 1 && left == -1)
                left = i;
        }
        if (data->token[i].type == CB)
        {
            bracket--;
            if (bracket == 0 && right == -1)
                right = i;
        }
    }
}