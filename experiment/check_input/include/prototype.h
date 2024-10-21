#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "struct.h"

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

// TREE
t_tree *create_node(void);
void branch(t_tree *node, int i);
void build_tree(t_tree *node);
t_tree *create_node(void);
int scan_bracket(t_tree *node);
int scan_operator(t_tree *node);
void visualize_tree(t_tree *node, int level);
void destroy_tree(t_tree *node);

// ENV
int create_env(t_data *data, char **env);
void destroy_env(t_data *data);
char *get_value(char *s, int size, t_env *head);
void view_env(t_data *data);

// RUN
void run_tree(t_tree *node, t_env *head);
char *swap_var(char *s, t_env *head);

// UTILS
int detection(char c, int *state);
void point_index(int index);
int is_blank(char *s); // change to isempty
char *special_join(char *s1, char *s2, char *s3);
void trim_off(char *s, int size);
int is_identifier(char *s);

#endif





