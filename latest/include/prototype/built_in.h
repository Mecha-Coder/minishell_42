#ifndef BUILT_IN_H
# define BUILT_IN_H

void	builtin_echo(char **av);
void	builtin_cd(char **av, t_shell *data);
void	builtin_pwd();

# endif