/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:03 by jetan             #+#    #+#             */
/*   Updated: 2024/10/04 16:25:00 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_numeric(char *str)
{
	int	i;
	
	i = -1;
	if ((str[0] == '-' || str[0] == '+') && (str[1] != '-' && str[1] != '+'))
		i = 1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

void	builtin_exit(char **av)
{
	int	exit_status;
	
	exit_status = 0;
	if (av[1] == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		exit(exit_status);
	}
	if (!is_numeric(av[1]))
	{
		ft_putstr_fd("exit\n", 2);
		error_message("exit", av[1], "numeric argument required");
		exit(2);
	}
	if (av[1] && av[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return;
	}
	exit_status = ft_atoi(av[1]);
	ft_putstr_fd("exit\n", 2);
	exit (exit_status);
	
}
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	builtin_exit(av);
// }