#include "../../include/minishell.h"

/* find_word
Purpose: Find first word pattern encountered in a string and return the index 
Pattern detection paused when inside quote
Param:
	s      : string
	len    : need 's' length because there is NULL \0 char in-between
    pattern: word pattern
Return: 
	FOUND    : index
	NO MATCH : -1
*/

int find_word(char *s, int len, char *pattern)
{
    int i;
    int j;
	int detect;
    
    (i = -1, detect = ON);
    while (++i < len)
    {
        j = 0;
        while (detection(s[i + j], &detect), detect == ON 
			&& s[i + j] == pattern[j])
        {
            if (!pattern[j + 1])
                return (i);
            j++;
        } 
    }
    return(-1);
}