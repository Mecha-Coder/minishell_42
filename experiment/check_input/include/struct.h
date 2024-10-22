#ifndef STRUCT_H
#define STRUCT_H

#include "constant.h"

typedef struct s_env
{
    char *key;
    char *val;
    struct s_env *next;
} t_env;

typedef struct s_token
{
    int type;
    int index;
    char *content;
    int malloc;
} t_token;

typedef struct s_tree
{
    t_token *token;
    int type;
    struct s_tree *left;
    struct s_tree *right;
    char *cmd[100];
    int in[10];
    int out[10];
} t_tree;

typedef struct s_data
{
    char *origin;
    char s[BUFFER_SIZE];
    int s_len;
    t_tree *root;
    t_token token[TOKEN_SIZE];
    t_env *env;
} t_data;

#endif