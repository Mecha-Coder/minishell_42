#include <token.h>

void tokenize_operator(char *s, int len, )
{
    int index;

    printf("Stage1: pop operator\n"
            "=====================\n");
    while(j < 100 && pattern[i][0])
    {
        index = find_word(s, len, pattern[i]);
        if (index >= 0)
        {
            token[j++] = (label){i, index, NULL};
            subtitute_null(s, index, strlen(pattern[i]));
        }
        else
            i++;
    }
}
