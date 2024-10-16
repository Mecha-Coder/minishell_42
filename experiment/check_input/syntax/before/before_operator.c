#include "../../include/minishell.h"

/* check_operator
Purpose: Count these symbols consecutive occurance meeting below rule.
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

static int symbol_A(char c)
{
	return (c == '<' || c == '|' || c == '>');
}

static int symbol_B(char c)
{
	return (c == '&');
}

static int check_occurance(char *s, int *occurance)
{
	int i;
	int symbol;

	if (!s && !(*s))
		return 0;
	(i = 0, *occurance = 1, symbol = s[i]);
	while (s[++i] && symbol == s[i])
		(*occurance)++;
	return (*occurance);
}

void before_operator(t_data *data, int *return_index)
{
	int i;
	int detect;
	int loop;
	int occurance;

	(i = -1, detect = ON, loop = TRUE);
	while(loop && data->s[++i])
	{	
		if (!detection(data->s[i], &detect) && detect == ON)
		{
			if ((symbol_A(data->s[i]) && check_occurance(&data->s[i], &occurance) > 2) 
				|| (symbol_B(data->s[i]) && check_occurance(&data->s[i], &occurance) != 2))
				loop = FALSE;
			i = occurance - 1;
		}
	}
	if (!loop)  *return_index = i;
	else        *return_index = -1;
}
