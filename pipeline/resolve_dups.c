/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/02 23:28:26 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups(t_ms *ms, int i)
{
	if (ms->cmds.out_fd != -1)
	{
		dprintf(2, "to aqui 1 out_fd: %d\n", ms->cmds.out_fd);
		dup42(ms->cmds.out_fd, STDOUT_FILENO);
	}
	else if (i == ms->parser.pipes_qtn - 1)
	{
		dprintf(2, "to aqui 2 out_fd: %d\n", ms->cmds.out_fd);
		return ;
	}
	else
	{
		dprintf(2, "to aqui 3 out_fd: %d\n", ms->cmds.out_fd);
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
		close(ms->cmds.fd[0]);
	}
}
