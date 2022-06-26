/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirect_from_end_of_str.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:07:59 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/26 04:44:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_str_from_matrix(t_ms *ms, int i);

void	remove_redirect_from_end_of_str(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[i])
	{
		if ((ms->cmds.command[i][0] == '<' && ms->cmds.command[i + 1])
		|| (ms->cmds.command[i][0] == '>' && ms->cmds.command[i + 1]))
		{
			remove_str_from_matrix(ms, i);
			remove_str_from_matrix(ms, i);
			continue ;
		}
		else if ((ms->cmds.command[i][0] == '<' && !ms->cmds.command[i + 1])
		|| (ms->cmds.command[i][0] == '>' && !ms->cmds.command[i + 1]))
		{
			free(ms->cmds.command[i]);
			ms->cmds.command[i] = NULL;
		}
		i++;
	}
}

static void	remove_str_from_matrix(t_ms *ms, int i)
{
	while (ms->cmds.command[i] && i < ft_mtxlen(ms->cmds.command))
	{
		free(ms->cmds.command[i]);
		if (ms->cmds.command[i + 1])
			ms->cmds.command[i] = ft_strdup(ms->cmds.command[i + 1]);
		else
			ms->cmds.command[i] = NULL;
		i++;
	}
}
