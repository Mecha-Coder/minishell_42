#ifndef EXECUTE_H
#define EXECUTE_H

#include "../struct.h"

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

#endif