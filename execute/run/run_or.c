/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:23:07 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/01 20:06:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void run_or(t_tree *node, t_shell *data)
{   
    descent_tree(node->left, data);
    if (!data->cmd_exit_no)
        return ;
    if (node->pipe)
    {
        close(node->pipe[0]);
        dup2(node->pipe[1], STDOUT_FILENO);
        close(node->pipe[1]);
    }
    descent_tree(node->right, data);
}