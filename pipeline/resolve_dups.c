/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/01 23:14:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups(t_ms *ms, int i)
{
	if (i == ms->parser.pipes_qtn - 1 && ms->cmds.out_fd != -1)
		dup42(ms->cmds.out_fd, STDOUT_FILENO);
	else if (i == ms->parser.pipes_qtn - 1)
		return ;
	else
	{
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
		close(ms->cmds.fd[0]);
	}
}
