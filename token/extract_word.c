/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:14:27 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/19 22:14:27 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_word(char c, int *detect, int sub);
static int	delimiter(char c);

#define NOW 0
#define PREV 1

/* >>> extract_word
Purpose:
- Take processed input after extract_token
- Split word by "space" delimiter and create token
==============================================================
Example
-                ON      |    OFF      | ON 
	Input:  Month   of   "November 2024"\0
		  0011111000110001111111111111110
-           ^    ^  ^ ^  ^              ^
-           S    C  S C  S              C               
==============================================================
Return 
- token *operator
- NULL, if no word found
*/

t_token	*extract_word(char *s, int sub)
{
	int		i;
	int		j;
	int		detect;
	int		x[2];
	t_token	*word;

	i = 0;
	detect = ON;
	word = NULL;
	x[PREV] = FALSE;
	while (1)
	{
		x[NOW] = is_word(s[i], &detect, sub);
		if (x[NOW] && !x[PREV])
			j = i;
		if (!x[NOW] && x[PREV])
			word = create_token(STR, ft_strndup(&s[j], i - j), j, word);
		x[PREV] = x[NOW];
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (token_jumpback(word));
}

static int	is_word(char c, int *detect, int sub)
{
	detection(c, detect, sub);
	if (*detect == ON && delimiter(c))
		return (FALSE);
	else
		return (TRUE);
}

static int	delimiter(char c)
{
	return (c == ' ' || c == '\0');
}

/* Test
int main()
{
	t_token *new;
	char s[] =  "out1.txt echo \">>>>> && out.txt\"   in.txt '|'";
	new = extract_word(s, FALSE);
	show_token(new, 'V');
	destroy_token(new);
}
 */
