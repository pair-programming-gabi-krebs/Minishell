/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_infile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:24:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/09 21:58:53 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups_infile(t_ms *ms, int i)
{
	if (ms->cmds.inf_fd != -1)
	{
		dprintf(2, "inf_fd |%d|\n", ms->cmds.inf_fd);
		dup42(ms->cmds.inf_fd, STDIN_FILENO);
	}
	else if (i >= 0 && ms->cmds.aux_fd != -1)
	{
		dprintf(2, "fd[0] |%d|\n", ms->cmds.fd[0]);
		dup42(ms->cmds.aux_fd, STDIN_FILENO);
	}
	else if (i >= 0 && ms->cmds.aux_fd == -1)
		dup42(ms->cmds.fd[0], STDIN_FILENO);
}


// void	resolve_dups_infile(t_ms *ms, int i)
// {
// 	if (i == -1 && ms->cmds.inf_fd != -1)
// 	{
// 		// if (ms->cmds.stin == -1)
// 		// 	ms->cmds.stin = dup(STDIN_FILENO);
// 		dprintf(2, "dentro do i == -1 && inf_fd != -1\n");
// 		dup42(ms->cmds.inf_fd, STDIN_FILENO);
// 	}
// 	else if (i >= 0 && ms->cmds.inf_fd != -1)
// 	{
// 		// if (i == 0 && ms->cmds.stin == -1)
// 		// 	ms->cmds.stin = dup(STDIN_FILENO);
// 		dup42(ms->cmds.inf_fd, STDIN_FILENO);
// 	}
// 	else if (i >= 0)
// 	{
// 		// if (i == 0 && ms->cmds.stin == -1)
// 		// 	ms->cmds.stin = dup(STDIN_FILENO);
// 		dprintf(2, "inf_fd i: %d - %d\n", ms->cmds.inf_fd, i);
// 		if (ms->cmds.inf_fd == -1)
// 			dup42(ms->cmds.fd[0], STDIN_FILENO);
// 		else
// 			dup42(ms->cmds.inf_fd, STDIN_FILENO);
// 	}
// }
