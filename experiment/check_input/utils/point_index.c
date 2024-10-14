#include "../include/minishell.h"

void highlight_index(int index)
{
	int i;

	i = 0;
	while(i++ < index)
		printf(" ");
	printf("↑\n");
}