#ifndef DEFINES_H
# define DEFINES_H

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
    int malloc; // FALSE, Indicate if content in dynamic memory
} t_token;

typedef struct s_tree
{
    int type;
    t_token *token;
    struct s_tree *left;
    struct s_tree *right;

    // During creation memset these values
    char *cmd;    // NULL
    int in;   // Must be > 2
    int out; // Must be > 2
    int *pipe_in;
    int *pipe_out;
} t_tree;

typedef struct s_shell
{
    t_env *env;

    // Need to reset
    char *input;
    char s;
    int s_len;
    t_tree *tree;
    t_token token;
    int token_len;
    int exit_cmd_no;
    int exit_status;
} t_shell;

#endif