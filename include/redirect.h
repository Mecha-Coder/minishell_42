#ifndef REDIRECT_H
#define REDIRECT_H

int	run_heredoc(t_tree *node);
int do_redirect(t_token *current);
void manage_io(int *fd, int action);

#endif
