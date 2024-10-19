#include "../include/minishell.h"

int is_alphabet(char c) 
{
    return ((c >= 'a' && c <= 'z') 
            || (c >= 'A' && c <= 'Z') 
            || (c == '_'));
}

int is_digit(char c) 
{
    return (c >= '0' && c <= '9');
}

int is_alnum(char c) 
{
    return (is_alphabet(c) || is_digit(c));
}


/* Test case

[OK]
./a.out "hello_world1"
./a.out "varName"
./a.out "_underscore"
./a.out "item1"
./a.out "longVariableNameWithMixedCase"
./a.out "MAX_VALUE"
./a.out "a"
./a.out "_2fast"
./a.out "data123"
./a.out "record_"
./a.out "__init__"


[K0]
./a.out "42_not_valid"
./a.out "123item"
./a.out "variable-name"
./a.out "float*"
./a.out "my var"
./a.out "@user"
./a.out "while$"
./a.out "char"
./a.out "name#"

[ANOTHER]
./a.out "USER$HANTUloo"
./a.out "SHELL  ' $SHELL ' && XX]\""
./a.out "SHELL$HOME"
./a.out "\!loo"
*/

int is_identifier(char *s)
{
    int i;

    i = 0;
    if (!is_alphabet(s[i]))
        return (i);
    while(s[++i])
    {
        if (!is_alnum(s[i]))
            return (i);
    }
    return (i);
}

/*
int main(int ac, char **av) 
{    
    if (ac == 2 && av[1][0])
    {
        printf("identifier size = %d\n", is_identifier(av[1]));

        // if (is_identifier(av[1]))
        //     printf(GREEN "Valid identifier = " RESET "\"%s\"\n", av[1]);
        // else
        //     printf(RED "Invalid identifier = " RESET "\"%s\"\n", av[1]);
    } 
    return 0;
}
*/



