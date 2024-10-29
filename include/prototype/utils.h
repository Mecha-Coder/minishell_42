#ifndef UTILS_H
#define UTILS_H

#include "../struct.h"

int blank_char(char c);
int detection(char c, int *state);
int is_empty(char *s);
void point_index(int index);
int token_len(t_token *token);
void free_list(char **list);
char *join_str(char *s1, char *s2);
char *get_var(char *key, t_env *current);

#endif