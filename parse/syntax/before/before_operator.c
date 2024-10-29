#include "../../../include/minishell.h"

#define TYPE 0
#define COUNT 1

static int symbol_1(char c);
static int symbol_2(char c);

/* Test
void answer(char *s)
{
	t_shell data;
	int index;
	int trigger;

	printf("\n%s\n", s);
	strcpy(data.s, s); 
	if (before_operator(&data, &index, &trigger), index >= 0)
	{
		point_index(index);
		printf("\nSyntax: " RED " ERROR\n" RESET);
	}
	else
		printf("\nSyntax: " GREEN "OK\n" RESET);
	printf("------------------------------------------------\n");
}

int main()
{
	printf ("\n--> OK TEST\n\n");
	answer("(echo 5) > out.txt");
	answer(" ls -l | (grep ic)");
	answer("ls out.txt >");
	answer("cat eval.h | cat | |cat | ls");
	answer("pwd && (mkdir new && cd new) && pwd && rmdir new");
	answer("(echo \"World\" && (echo \"Hello\"))");
	answer("(export a=10 && echo $a) && echo $a");
	answer("pwd && (cd ../ && pwd) && pwd << EOF");
	answer("ls -l && (echo hello && echo nice to meet you)");
	answer("| ls | wc -l > > out.txt");
	answer("env | grep SHLVL && (env | grep SHLVL)");

	printf ("\n--> ERROR TEST\n\n");
	answer("echo hello & (echo done)");
	answer("echo bonjour  >>>  test");
	answer("cat XXX || echo ok ||| echo  done");
	answer("ls >>> in.txt");
	return (0);
}
 */

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
void before_operator(t_shell *data, int *return_index, int *trigger)
{
	int i;
	int j;
	int detect;
	int loop;
	
	(i = -1, detect = ON, loop = TRUE, *trigger = 3);
	while (loop && data->s[++i])
	{
		if (!detection(data->s[i], &detect) && detect == ON 
			&& (symbol_1(data->s[i]) || symbol_2(data->s[i])))
		{
			j = 0;
			while (data->s[i] == data->s[i + j])
				j++;
			if ((symbol_1(data->s[i]) && j > 2) 
				|| (symbol_2(data->s[i]) && j != 2))
				loop = FALSE;
			else
				i += j - 1;
		}
	}
	if (!loop)  *return_index = i;
	else        *return_index = -1;
}

static int symbol_1(char c)
{
	return (c == '<' || c == '|' || c == '>');
}

static int symbol_2(char c)
{
	return (c == '&');
}

/*
static int check_occurance(char *s, int *occurance)
{
	int i;
	int symbol;

	(i = 0, *occurance = 1, symbol = s[i]);
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
*/
