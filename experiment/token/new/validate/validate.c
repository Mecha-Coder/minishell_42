#include "../include/token.h"

/* validate
Purpose: Check syntax after tokenize

a) Single & shouldn't exist

7
&

b) Redirection operator must be followed by <STR>

 2   3   4     5    10
<<   <   >>    >  <STR>

c) These operator left & right need to be <STR> or <OB> <CB>
 
 0  1   6
||  |  &&   

                            ↓
d) Bracket unpack by stages (())

<START><OPERATOR>  (  <STR>
                   ↑
             check in pair
                   ↓
            <STR>  )  <OPERATOR><END>
             
                (<STR>)
            ( <OB>   <!CB>)
            ( <!OB>  <CB> )  
            

OK
echo hello && (echo) && echo hi  ✅
echo hello && (echo nice && ls) && echo hi ✅
echo hello && (echo nice && (ls)) && echo hi ✅
(echo hello) ✅
echo hello | (cat) ✅
(ls) ✅
ls && (ls && (ls && (ls && (ls && (ls && (ls)))))) && ls

ERROR
((echo hello))
echo hello && (echo (nice)) && echo hi ❌
echo hello && () && echo hi ❌
echo hello && (echo nice (ls)) && echo hi ❌
echo hello && ((echo nice && (ls))) && echo hi
*/ 

void indicate_syntax_error(int i, int trigger)
{
    point_index(i);
    if (trigger == 1)
        printf("\nSyntax: " RED " ERROR: Found XAND\n" RESET);
    else if (trigger == 2)
        printf("\nSyntax: " RED " ERROR: Wrong redirect\n" RESET);
    else if (trigger == 3)
        printf("\nSyntax: " RED " ERROR: Wrong used of operator\n" RESET);
	
}

int validate(t_data *data)
{
    int index;
    int trigger;

    printf("\n%s\n", data->origin);

    if ((and(data, &index), trigger = 1, index >= 0)
        || (redirect(data, &index), trigger = 2, index >=0)
        || (operator(data, &index), trigger = 3, index >=0))
    {
        return(indicate_syntax_error(index, trigger), FALSE);
    }
        
    printf("\nSyntax: " GREEN "OK\n" RESET);
    return (TRUE);
    
}