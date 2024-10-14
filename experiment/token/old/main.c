#include "token.h"

int main(int ac, char **av)
{
	if (ac == 2 && av[1] && av[1][0])
		tokenization(av[1]);
	return 0;
}

