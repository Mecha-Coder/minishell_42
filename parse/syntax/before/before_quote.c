#include "../../../include/minishell.h"

#define SQ 0
#define DQ 1
#define EVAL 2

/* Test
void answer(char *s)
{
	t_shell data;
	int index;
    int trigger;

	printf("\n%s\n", s);
	strcpy(data.s, s);
	if (before_quote(&data, &index, &trigger), index >= 0)
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
	answer("   echo  \"[Hello 'World'']\"");
	answer("echo hi\";\" hihi");
	answer("echo \"[Path \\$SHELL  '  ' && !]\"");
	answer("echo \"a\"s\"f\"g\"h\"");
	answer("echo 'a's'f'f'g'h");
	answer("rm non_existent_file || echo \"Exit staus: \\$?\" && echo \"Exit staus: \\$?\"");
	answer("(echo \"World\" && (echo \"Hello\"))");
	printf ("\n--> ERROR TEST\n\n");
	answer("echo \"EE");
	answer("echo \"Double quote: \"\"");
	answer("echo \"Done'\" '");
	answer("echo 'Done\"' \"");
	return (0);
}
*/

/* check_quote 
Purpose: Single (') and double (") count must be even (paired). 
Return: 
	KO : index of an unpaired quote
	OK : -1 (all quotes are paired)
*/
void before_quote(t_shell *data, int *return_index, int *trigger)
{
	int i;
	int detect;
	int count[2];
	int pos[3];

	(i = -1, detect = ON, *trigger = 1);
	memset(&count, 0, sizeof(count));
	while (data->s[++i])
	{
		pos[EVAL] = detection(data->s[i], &detect);
		if (pos[EVAL] == 1)       (count[DQ]++, pos[DQ] = i);
		else if (pos[EVAL] == 2)  (count[SQ]++, pos[SQ] = i);
		else if (pos[EVAL] == 3)  (count[DQ]++, pos[DQ] = i); 
		else if (pos[EVAL] == 4)  (count[SQ]++, pos[SQ] = i);
	}
	if (count[SQ] % 2)       *return_index = pos[SQ];
	else if (count[DQ] % 2)  *return_index = pos[DQ];
	else                     *return_index = -1;
}