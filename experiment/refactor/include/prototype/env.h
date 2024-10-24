#ifndef ENV_H
#define ENV_H

#include "../struct.h"

int setup_env(t_shell *data, char **env);
void destroy_env(t_shell *data);

#endif