#ifndef SPLIT_H
#define SPLIT_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

char **path_lvl(char *s, int len);
void free_list(char **result);
char **all_path(char **env);
int	get_len(char *s);
char	*join_str(char *s1, char *s2);

#endif