#ifndef MINISHELL_H
#define MINISHELL_H

//******************************************/

#include "constant.h"
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <unistd.h>

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

//SYNTAX - BEFORE
int check_syntax_before(t_data *data);
void before_quote(t_data *data, int *return_index);
void before_bracket(t_data *data, int *return_index);
void before_operator(t_data *data, int *return_index);

//SYNTAX - AFTER
int check_syntax_after(t_data *data);
void after_and(t_data *data, int *return_index);
void after_redirect(t_data *data, int *return_index);
void after_operator(t_data *data, int *return_index);
void after_bracket(t_data *data, int *return_index);

//TOKENIZE
int tokenize(t_data *data);
void pop_operator(t_data *data, int *j);
int find_word(char *s, int len, char *pattern);
void pop_str(t_data *data, int *j);
void sort_token(t_data *data);

// UTILS
int detection(char c, int *state);
void point_index(int index);
int is_blank(char *s);

#endif