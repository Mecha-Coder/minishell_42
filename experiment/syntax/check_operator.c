#include "syntax.h"

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

void check_operator(char *s, int *return_index)
{
	int i;
	int state;
	int loop;
	int occurance;

	(i = -1, state = ON, loop = TRUE);
	while(loop && s[++i])
	{	
		if (!ignore_detection(s[i], &state) && state == ON)
		{
			if ((symbol_A(s[i]) && check_occurance(&s[i], &occurance) > 2) 
				|| (symbol_B(s[i]) && check_occurance(&s[i], &occurance) != 2))
				loop = FALSE;
			i = occurance - 1;
		}
	}
	if (!loop)  *return_index = i;
	else        *return_index = -1;
}

void highlight_issue(int index)
{
	int i;

	i = 0;
	while(i++ < index)
		printf(" ");
	printf("↑\n");
}

void answer(char *s)
{
	int index;

	printf("\n%s\n", s);
	if (check_operator(s, &index), index >= 0)
	{
		highlight_issue(index);
		printf("\nSyntax: " RED " ERROR\n" RESET);
	}
	else
		printf("\nSyntax: " GREEN "OK\n" RESET);
	printf("------------------------------------------------\n");
}

int main()
{
	printf ("\n--> OK TEST\n\n");
	answer("echo \"Hello World\" | tr 'a-z' 'A-Z'");
	answer("cat eval.h | cat | cat | ls");
	answer("cat < in1.c < in2.c");
	answer("<< Hello << EOF cat");
	answer("< nonexist.txt << EOF cat");
	answer("cat in.txt << EOF > out1.txt >> out2.txt");
	answer("echo bonjour  h  >>out.txt");
	answer("> in1.txt | ls");
	answer("cd ../../../../ && pwd");
	answer("(export a=10 && echo \\$a) && echo \\$a");
	answer("pwd && (mkdir new && cd new) && pwd && rmdir new");
	answer("pwd || rm xx  && echo done1  || echo done2");
	answer("export TEST=* && echo \\$TEST");
	answer(" cat in.txt | cat | cat > out.txt | cat >> out.txt > err.txt");

	printf ("\n--> ERROR TEST\n\n");
	answer("cat eval.h | cat | |cat | ls");
	answer("cat < <");
	 answer("echo bonjour  >>>  test");
	answer("> out1.txt echo \">>>>> out.txt\" < in.txt");
	answer("touch file.txt ||  | echo \"Failed to create file\"");
	answer("touch file.txt &&& echo \"Failed to create file\"");
	answer("touch file.txt &");
	answer("touch & file.txt");
	return (0);
}