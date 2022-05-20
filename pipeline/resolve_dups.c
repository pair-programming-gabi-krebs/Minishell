/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/19 20:51:57 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups(t_ms *ms, int i)
{
	printf("ms->parser.pipes_qtn: %d\n", ms->parser.pipes_qtn);
	if (i == ms->parser.pipes_qtn - 1)
	{
		int	tmp;
		tmp = open("testDup", O_RDWR | O_CREAT | O_TRUNC, 0777);
		printf("tmp: %d\n", tmp);
		dup42(tmp, ms->cmds.fd[1]);
	}
	else
		dup42(ms->cmds.fd[1], STDOUT_FILENO);
}
