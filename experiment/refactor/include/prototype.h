#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "struct.h"

// ENV
int setup_env(t_shell *data, char **env);
void show_env(t_shell *data);
void clear_env(t_shell *data);

// SYNTAX - BEFORE
int check_syntax_before(t_shell *data);
void before_quote(t_shell *data, int *return_index, int *trigger);
void before_bracket(t_shell *data, int *return_index, int *trigger);

// SYNTAX - AFTER


// UTIL 
int blankchar(char c);
int detection(char c, int *state);
int isempty(char *s);
void point_index(int index);

#endif