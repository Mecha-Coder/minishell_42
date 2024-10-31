#ifndef EXECUTE_H
#define EXECUTE_H

#include "../struct.h"

//EXECUTE
void run_ast(t_shell *data);
int run_cmd(t_tree *node, t_shell *data);
int run_pipe(t_tree *node, t_shell *data);
int descent_tree(t_tree *node, t_shell *data);

//POLISH
int polish_str_token(t_token *token, t_shell *data);
char *get_value(char *s, int size, t_env *head);
int is_identifier(char *s, int *i);
char *join3(char *s1, char *s2, char *s3);
char *swap_var(char *s, t_shell *data);
void sub_single_quote(char *s, int convert_status);

//PATH
char **all_path(t_env *list);
char *get_path(char *s, t_env *list);
void parse_path(char *s, char **path);

//CMD
void prep_cmd(t_tree *node);
void none_builtin(char **cmd, t_env *list);
char **env_list(t_env *current);
#endif