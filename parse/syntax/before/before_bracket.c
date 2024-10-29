#include "../../../include/minishell.h"

#define COUNT 0
#define POS_OPEN 1

static void check_inside(char *s, int i, int *bracket);

/* Test
void answer(char *s)
{
	t_shell data;
	int index;
	int trigger;

	printf("\n%s\n", s);
	strcpy(data.s, s); 
	if (before_bracket(&data, &index, &trigger), index >= 0)
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
	answer("echo \\$((3+ 5))");
	answer(" ls -l | (grep ic)");
	answer("echo hello & (echo done)");
	answer("( echo hello ) && (( echo hi  )  ");
	answer("pwd && (mkdir new && cd new) && pwd && rmdir new");
	answer("(echo \"World\" && (echo \"Hello\"))");
	answer("(export a=10 && echo $a) && echo $a");
	answer("pwd && (cd ../ && pwd) && pwd");
	answer("ls -l && (echo hello && echo nice to meet you)");
	answer("(ls -l && (echo hello && echo nice to meet you))");
	answer("env | grep SHLVL && (env | grep SHLVL)");

	printf ("\n--> ERROR TEST\n\n");
	answer("() && echo done ()");
	answer("() && (                   )");
	answer(") ) echo hello ( ( || cat");
	answer("()");
	return (0);
}
*/

/* before_bracket
Purpose: () must be paired in this arrangement. 
        Inside can't be empty (). 
        Incorrect pair (( or )(.
Return: 
	KO : index of an incorrect bracket
	OK : -1
*/
void before_bracket(t_shell *data, int *return_index, int *trigger)
{
	int i;
	int bracket[2];
	int detect;

	(i = -1, detect = ON, bracket[COUNT] = 0, *trigger = 2);
	while (bracket[COUNT] >= 0 && data->s[++i])
	{
		if (!detection(data->s[i], &detect) && detect == ON)
		{
			if (data->s[i] == '(')      (bracket[COUNT]++, bracket[POS_OPEN] = i);
			else if (data->s[i] == ')') (bracket[COUNT]--, check_inside(data->s, i, bracket));
		}
	}
	if (bracket[COUNT] > 0)       *return_index = bracket[POS_OPEN];
    else if (bracket[COUNT] < 0)  *return_index = i;
	else                          *return_index = -1;
}


static void check_inside(char *s, int i, int *bracket)
{
    if (bracket[COUNT] < 0)
        return;
    while (s[--i] != '(')
    {
        if (!blank_char(s[i]))
            return;
    }
     bracket[COUNT] = -1;
}