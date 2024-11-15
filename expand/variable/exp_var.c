/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:22:55 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/15 16:04:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define S_QUOTE 1
#define D_QUOTE 2

#include "../../include/minishell.h"

void del_quote(char *s, int type);

/* >>> exp_var
Purpose
- Scan for variable ($_ _ _) in string 
- Then swap/insert it coresponding value
=============================================================================
Rule
- $?            : expand to cmd_exit_no
- $[digit: 1-9] : blank
- $[identifier] : check key=identifier in env, expand to that
                : else blank

Note: If not meeting rule, don't expand, leave it
=============================================================================
Example
- Input  : "This is $USER's pc named '$1$?$h'"
- Output :  This is jpaul's pc named '0'
=============================================================================
Return
- char : expanded string (malloc)
=============================================================================
Side effect
- The 1st param (char *s) is malloc
- exp_var will help to free it.
*/

char *exp_var(char *s, t_shell *data)
{
    char *new;

    sub_squote(s, TRUE);
    del_quote(s, D_QUOTE);
    if (contain_var(s))
    {
        new = insert_var(s, data);
        free(s);
        s = new;
    }
    del_quote(s, S_QUOTE);
    sub_squote(s, FALSE);
    return (s);
}

int contain_var(char *s)
{
    int i;
    int detect;

    while (s && s[++i])
    {
        detection(s[i], &detect);
        if (detect != SQ_OFF && s[i] == '$')
            return (TRUE);
    }
    return (FALSE);
}

void del_quote(char *s, int type)
{
    int i;
    int j;
    int num;
    int detect;
    char *temp;

    (i = -1, j = 0, detect = ON);
    temp = (char *)malloc(ft_strlen(s) + 1);
    if (!temp)
    {
        perror("Malloc fail");
        exit(EXIT_FAILURE);
    }
    while (s && s[++i])
    {
        num = detection(s[i], &detect);
        if (type == D_QUOTE && num != 1 && num != 3)
            temp[j++] = s[i];
        if (type == S_QUOTE && num != 2 && num != 4)
            temp[j++] = s[i];
    }
    temp[j] = '\0';
    ft_strcpy(s, temp);
    free(temp);
}