/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_redirect_position.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:10:20 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:10:29 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_last_redirect_position(t_ms *ms, int i)
{
	int	stop_count;

	stop_count = 0;
	while (ms->cmds.command[i] && stop_count < 2)
	{
		if (ms->cmds.command[i][0] == '<' && ms->cmds.command[i + 1])
		{
			ms->parser.last_redirect = ms->parser.last_redirect + 2;
			stop_count = 0;
		}
		else if (ms->cmds.command[i][0] == '>' && ms->cmds.command[i + 1])
		{
			ms->parser.last_redirect = ms->parser.last_redirect + 2;
			stop_count = 0;
		}
		else
			stop_count++;
		i++;
	}
	return (i);
}
