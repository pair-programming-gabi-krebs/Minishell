/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:21:54 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_for_redirects(t_ms *ms)
{
	int	i;
	int	out_counter;
	int	inf_counter;

	out_counter = 0;
	inf_counter = 0;
	i = 0;
	while (ms->cmds.command[i])
	{
		if (ms->cmds.command[i][0] == '<')
		{
			get_redirect_name(ms, ms->cmds.inf, i, inf_counter);
			inf_counter++;
		}
		else if (ms->cmds.command[i][0] == '>')
		{
			get_redirect_name(ms, ms->cmds.out, i, out_counter);
			out_counter++;
		}
		i++;
	}
	if (inf_counter == 0)
	{
		free_matrix(ms->cmds.inf);
		ms->cmds.inf = malloc(2048 * sizeof(char **));
		ms->cmds.inf[0] = NULL;
		ms->cmds.out_fd = -1;
	}
	if (out_counter == 0)
	{
		free_matrix(ms->cmds.out);
		ms->cmds.out = malloc(2048 * sizeof(char **));
		ms->cmds.out[0] = NULL;
		ms->cmds.out_fd = -1;
	}
	if (inf_counter > 0 || out_counter > 0)
		return (1);
	return (0);
}
