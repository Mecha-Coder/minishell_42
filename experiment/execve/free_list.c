#include "split.h"

void free_list(char **result)
{
    int i;

    i = -1;
    while (result && result[++i])
        free (result[i]);
    if (result)
        free(result);
}