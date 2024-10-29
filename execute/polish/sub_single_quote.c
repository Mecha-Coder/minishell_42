#include "../../include/minishell.h"

/* sub_single_quote
Purpose: Subtitute (') quote inside "double quote" temporarily.
    WHY! Polish stage remove '' and "" but exclude those inside. 
    To prevent accidental deletion of (') sub to ASCII -> 26
*/
void sub_single_quote(char *s, int convert_status)
{
    int i;
    int detect;

    (i = -1, detect = ON);
    while (convert_status && s[++i])
    {
        if (detection(s[i], &detect), detect == DQ_OFF 
            && s[i] == '\'')
        {
            s[i] =(char)26;
        }
    }
    while (!convert_status && s[++i])
    {
        if (s[i] == (char)26)
            s[i] = ('\'');
    }
}