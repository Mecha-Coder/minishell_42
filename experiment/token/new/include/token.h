#ifndef TOKEN_H
#define TOKEN_H

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
    t_token token[TOKEN_LIST];
} t_data;


//*********************************************
// Prototype
//*********************************************


//TOKENIZE
void tokenize(t_data *data);
void pop_operator(t_data *data, int *j);
int find_word(char *s, int len, char *pattern);
void pop_str(t_data *data, int *j);
void sort_token(t_data *data);

// UTILS
int detection(char c, int *state);



#endif