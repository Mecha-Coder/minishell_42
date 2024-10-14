#ifndef MINISHELL_H
#define MINISHELL_H

//******************************************/

#include "constant.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

//*********************************************

typedef struct s_token
{
    int type;
    int index;
    char *content;
} t_token;


typedef struct s_data
{
    char *origin;
    char s[BUFFER_SIZE];
    int s_len;
    t_token token[TOKEN_SIZE];
} t_data;


//*********************************************
// Prototype
//*********************************************


//TOKENIZE



#endif