/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/07 00:12:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups_outfile(t_ms *ms, int i)
{
	if (ms->cmds.out_fd != -1)
		dup42(ms->cmds.out_fd, STDOUT_FILENO);
	else if (i == ms->parser.pipes_qtn - 1)
		dup42(ms->cmds.stout, STDOUT_FILENO);
	else
	{
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
		//close(ms->cmds.fd[0]);
	}
}
