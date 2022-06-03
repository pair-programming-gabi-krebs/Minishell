/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirect_from_end_of_str.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:07:59 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:08:39 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_redirect_from_end_of_str(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[i])
	{
		if (ms->cmds.command[i][0] == '<' && ms->cmds.command[i + 1])
		{
			free(ms->cmds.command[i]);
			free(ms->cmds.command[i + 1]);
			ms->cmds.command[i] = NULL;
			ms->cmds.command[i + 1] = NULL;
		}
		else if (ms->cmds.command[i][0] == '>' && ms->cmds.command[i + 1])
		{
			free(ms->cmds.command[i]);
			free(ms->cmds.command[i + 1]);
			ms->cmds.command[i] = NULL;
			ms->cmds.command[i + 1] = NULL;
		}
		i++;
	}
}
