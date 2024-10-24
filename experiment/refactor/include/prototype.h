#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "struct.h"

// ENV
int setup_env(t_shell *data, char **env);
void clear_env(t_shell *data);

// SYNTAX - BEFORE
int check_syntax_before(t_shell *data);
void before_quote(t_shell *data, int *return_index, int *trigger);
void before_bracket(t_shell *data, int *return_index, int *trigger);
void before_operator(t_shell *data, int *return_index, int *trigger);

// SYNTAX - AFTER
void after_bracket(t_shell *data, int *return_index, int *trigger);
void after_operator(t_shell *data, int *return_index, int *trigger);
void after_redirect(t_shell *data, int *return_index, int *trigger);
int check_syntax_after(t_shell *data);

// TOKEN
int find_word(char *s, int len, char *pattern);
void pop_operator(t_shell *data, int *j);
void pop_str(t_shell *data, int *j);
void sort_token(t_shell *data);
int tokenize(t_shell *data);
void free_str_token(t_shell *data);

//TREE
int build_ast(t_shell *data);
void clear_ast(t_shell *data);
t_tree *create_node(void);
int scan_bracket(t_tree *node);
int scan_operator(t_tree *node);

//EXECUTE
void run_ast(t_shell *data);
void prep_exe(t_tree *node);

//POLISH
int polish_str_token(t_token *token, t_env *list);
char *get_value(char *s, int size, t_env *head);
int is_identifier(char *s, int *i);
char *join3(char *s1, char *s2, char *s3);
char *swap_var(char *s, t_env *list);
void sub_single_quote(char *s, int convert_status);

// UTIL 
int blankchar(char c);
int detection(char c, int *state);
int isempty(char *s);
void point_index(int index);
int token_len(t_token *token);

// VISUAL
void show_env(t_shell *data);
int show_token(t_shell *data);
void show_ast(t_shell *data);
#endif