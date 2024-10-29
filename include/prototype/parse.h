#ifndef PARSE_H
#define PARSE_H

#include "../struct.h"

// SYNTAX - BEFORE
int check_syntax_before(t_shell *data);
void before_quote(t_shell *data, int *return_index, int *trigger);
void before_bracket(t_shell *data, int *return_index, int *trigger);
void before_operator(t_shell *data, int *return_index, int *trigger);

// SYNTAX - AFTER
int check_syntax_after(t_shell *data);
void after_bracket(t_shell *data, int *return_index, int *trigger);
void after_operator(t_shell *data, int *return_index, int *trigger);
void after_redirect(t_shell *data, int *return_index, int *trigger);

// TOKEN
int find_word(char *s, int len, char *pattern);
void pop_operator(t_shell *data, int *j);
void pop_str(t_shell *data, int *j);
void free_str_token(t_shell *data);
int tokenize(t_shell *data);
void sort_token(t_shell *data);

//TREE
t_tree *create_node(void);
int build_ast(t_shell *data);
void destroy_ast(t_shell *data);
int scan_bracket(t_tree *node);
int scan_operator(t_tree *node);

#endif