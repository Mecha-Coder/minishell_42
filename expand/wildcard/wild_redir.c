/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:28:59 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 14:00:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> wild_redir
Purpose: 
- Match wildcard pattern against files/folders in the current dir.
- Loop each entry, can only have one or no match entry
===========================================================================
Param
- char **match  : Reference pointer to be used by parent
- char *pattern : Wildcard pattern

===========================================================================
Return
- TRUE : Match <= 1
- FALSE: Match >1

===========================================================================
Side effect
- Update the char **match pointer either
    * Found 1 (malloc)
    * NULL
*/

int wild_redir(char **match, char *pattern)
{
    DIR *dir;
    struct dirent *entry;
    
    (*match = NULL, dir = opendir("."));
    if (!dir)
    {
        perror("Opendir fail");
        exit(EXIT_FAILURE);
    }
    entry = readdir(dir);
    while (entry)
    {
        if (wild_match(entry->d_name, pattern))
        {
            if (!(*match))
                *match = ft_strdup(entry->d_name);
            else
                return (free(*match), closedir(dir), FALSE);
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return (TRUE);
}


/* Test
void answer(char *pattern)
{
    char *s;

    sub_wild(pattern, TRUE);
    if (wild_redir(&s, pattern))
    {
        if (s)
        {
            printf("%s\n", s);
            free (s);
        }
        else  printf("NULL\n");
    }
    else printf("Ambiguous error prompt\n");
    printf("\n------------------------\n");
}

int main()
{   
    
    printf ("\n========== OK (MATCH)=========\n\n");
    char s1[] = "file*";
    char s2[] = "*logx";
    char s3[] = "*ex*"; 

    answer(s1);
    answer(s2);
    answer(s3);
    printf ("\n========== OK (NO MATCH)=========\n\n");

    char s4[] = "*tt*";
    char s5[] = "*none*";

    answer(s4);
    answer(s5);

    printf ("\n========== ERROR=========\n\n");
    char s6[] = "d*m*";
    char s7[] = "*";
    
    answer(s6);
    answer(s7);
}
 */



