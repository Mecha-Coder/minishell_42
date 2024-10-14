#ifndef TOKEN_H
#define TOKEN_H

/****************************************** */

#include "constant.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

/****************************************** */

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"

/****************************************** */

typedef struct s_token
{
    int type;
    int index;
    char *content;
} t_token;

typedef struct s_data
{
    char s[1024];
    int s_len;
    t_token token[100];
} t_data;

/****************************************** */

// LOGIC
void tokenize(char *s);

// UTILS
int detection(char c, int *state);
int find_word(char *s, int len, char *pattern);

#endif