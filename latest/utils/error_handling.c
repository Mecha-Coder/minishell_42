#include "../include/minishell.h"

void	error_msg_export(char *builtin, char *arg, char *msg)
{
	printf("minishell: ");
	ft_putstr_fd(builtin);
	ft_putstr_fd(": ");
	ft_putstr_fd("`arg'");
	ft_putstr_fd(": ");
	ft_putstr_fd(msg);
	ft_putstr_fd("\n");
}

void	error_arg_msg(char *builtin, char *arg, char *msg)
{
	ft_putstr_fd("minishell: ");
	ft_putstr_fd(builtin);
	ft_putstr_fd(": ");
	ft_putstr_fd(arg);
	ft_putstr_fd(": ");
	ft_putstr_fd(msg);
	ft_putstr_fd("\n");
}

void	error_msg(char *builtin, char *msg)
{
	ft_putstr_fd("minishell: ");
	ft_putstr_fd(builtin);
	ft_putstr_fd(": ");
	ft_putstr_fd(msg);
	ft_putstr_fd("\n");
}

void	arg_count(char **args, char *builtin)
{
	int		count;
	
	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		error_msg(builtin, "too many arguments");
		return;
	}
}