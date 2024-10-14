#ifndef SYNTAX_H
#define SYNTAX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//********************************************************

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"

//********************************************************

// quote detection status
#define ON 0
#define TRUE 1
#define FALSE 0

//********************************************************

int ignore_detection(char c, int *state);
void check_quote_count(char *s, int *return_index);

#endif
