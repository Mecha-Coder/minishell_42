#include "../../include/minishell.h"

/* check_operator
Purpose: Check symbol consecutive occurance meeting below rule.
operator occur  <= 2 
    < , <<  
	> , >> 
	| , ||
operator occur == 2
	&&
Return: 
	KO : index of symbol in question
	OK : -1
*/

#define TYPE 0
#define COUNT 1

static int symbol_1(char c)
{
	return (c == '<' || c == '|' || c == '>');
}

static int symbol_2(char c)
{
	return (c == '&');
}

static int check_occurance(char *s, int *occurance)
{
	int i;
	int symbol;

	(i = 0, *occurance = 1, symbol = s[i]);
	if (!s || !(*s))
		return 0;
	while (s[++i] && symbol == s[i])
		(*occurance)++;
	return (*occurance);
}

void before_operator(t_shell *data, int *return_index, int *trigger)
{
	int i;
	int detect;
	int loop;
	int occurance;

	(i = -1, detect = ON, loop = TRUE, occurance = 0);
	while(loop && data->s[++i])
	{	
		if (!detection(data->s[i], &detect) && detect == ON)
		{
			if (symbol_1(data->s[i]))
			{
				if (check_occurance(&data->s[i], &occurance) > 2)
					loop = FALSE;
				else
					i += occurance - 1;
			}
			if (symbol_2(data->s[i]))
			{
				if (check_occurance(&data->s[i], &occurance) != 2)
					loop = FALSE;
				else
					i += occurance - 1;
			}
		}
	}
	if (!loop)  *return_index = i;
	else        *return_index = -1;
}
