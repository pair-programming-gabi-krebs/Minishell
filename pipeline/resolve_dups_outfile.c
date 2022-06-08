/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/08 19:09:33 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups_outfile(t_ms *ms, int i)
{
	if (ms->cmds.out_fd != -1)
	{
		dprintf(2, "out_fd |%d|\n", ms->cmds.out_fd);
		dup42(ms->cmds.out_fd, STDOUT_FILENO);
	}
	else if (i == ms->parser.pipes_qtn - 1)
	{
		dprintf(2, "stout |%d|\n", ms->cmds.stout);
		dup42(ms->cmds.stout, STDOUT_FILENO);
	}
	else
	{
		dprintf(2, "fd[1] |%d|\n", ms->cmds.fd[1]);
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
	}
}


// void	resolve_dups_outfile(t_ms *ms, int i)
// {
// 	if (ms->cmds.out_fd != -1)
// 		dup42(ms->cmds.out_fd, STDOUT_FILENO);
// 	else if (i == ms->parser.pipes_qtn - 1)
// 	{
// 		dprintf(2, "to aqui i: %d\n", i);
// 		dprintf(2, "command: %s\n", ms->cmds.command[0]);
// 		// close(STDOUT_FILENO);
// 		// close(ms->cmds.stout);
// 		close(ms->cmds.stin);
// 		dup42(ms->cmds.stout, STDOUT_FILENO);
// 		//close(1);
// 		//dup42(ms->cmds.stin, STDIN_FILENO);
// 		// close(ms->cmds.fd[0]);
// 		//close(STDIN_FILENO);
// 		// ;
// 	}
// 	else
// 	{
// 		dup42(ms->cmds.fd[1], STDOUT_FILENO);
// 		if (!is_builtin(ms))
// 			close(ms->cmds.fd[0]);
// 	}
// }
