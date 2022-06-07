/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_infile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:24:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/07 00:00:54 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups_infile(t_ms *ms, int i)
{
	if (i == -1 && ms->cmds.inf_fd != -1)
	{
		// if (ms->cmds.stin == -1)
		// 	ms->cmds.stin = dup(STDIN_FILENO);
		dup42(ms->cmds.inf_fd, STDIN_FILENO);
	}
	else if (i >= 0 && ms->cmds.inf_fd != -1)
	{
		// if (i == 0 && ms->cmds.stin == -1)
		// 	ms->cmds.stin = dup(STDIN_FILENO);
		dup42(ms->cmds.inf_fd, STDIN_FILENO);
	}
	else if (i >= 0)
	{
		// if (i == 0 && ms->cmds.stin == -1)
		// 	ms->cmds.stin = dup(STDIN_FILENO);
		if (ms->cmds.inf_fd == -1)
			dup42(ms->cmds.fd[0], STDIN_FILENO);
		else
			dup42(ms->cmds.inf_fd, STDIN_FILENO);
	}
}
