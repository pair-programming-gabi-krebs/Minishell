/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/20 00:02:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups(t_ms *ms, int i)
{
	if (i == ms->parser.pipes_qtn - 1)
		return ;
	else
	{
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
		close(ms->cmds.fd[0]);
	}
}
