#ifndef MINISHELL_H
#define MINISHELL_H

// Mute this headers after finalize
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
//#include <sys/wait.h>

#include "constant.h"
#include "struct.h"

#include "./prototype/built_in.h"
#include "./prototype/env.h"
#include "./prototype/execute.h"
#include "./prototype/parse.h"
#include "./prototype/utils.h"
#include "./prototype/visual.h"

#endif