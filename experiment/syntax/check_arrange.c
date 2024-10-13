#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
<Redirect><STR>  Redirect must be followed by 
	<STR> <- && -> <STR>  &&, ||,  must have <STR> on left and right
*/


 
typedef struct s_label
{
    int type;
    char *content;
} label;


int tokenize(char *s)
{
    label token[100];
    int i = 0;
    int state;
    int detection;

    while (i < 99 && state != END_)
    {
        j = 0
        while()
        {
            s[j]
        }
        
    }
    
}



int main(int ac, char **av)
{
	if (ac == 2 && av[1] && av[1][0])
		tokenize(av[1]);
	return 0;
}

