#ifndef UTILS_H
#define UTILS_H

#include "../struct.h"

int blank_char(char c);
int detection(char c, int *state);
int is_empty(char *s);
void point_index(int index);
int token_len(t_token *token);

#endif