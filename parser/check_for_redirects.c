/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/10 00:36:34 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	redirect_validations(t_ms *ms, int inf_counter, int out_counter);

int	check_for_redirects(t_ms *ms)
{
	int	i;
	int	out_counter;
	int	inf_counter;
	int	hdoc_counter;

	out_counter = 0;
	inf_counter = 0;
	hdoc_counter = 0;
	ms->cmds.append_flag = 0;
	i = 0;
	while (ms->cmds.command[i])
	{
		if (!strict_strcmp(ms->cmds.command[i], "<<")
			&&  ms->cmds.command[i + 1])
		{
			ms->cmds.limiter = ms->cmds.command[i + 1];
			here_doc(ms);
			hdoc_counter++;
		}
		else if (!strict_strcmp(ms->cmds.command[i], ">>")
			&&  ms->cmds.command[i + 1])
		{
			get_redirect_name(ms, ms->cmds.out, i, out_counter);
			out_counter++;
			ms->cmds.append_flag = 1;
		}
		else if (ms->cmds.command[i][0] == '<')
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
	redirect_validations(ms, inf_counter, out_counter);
	if (inf_counter > 0 || out_counter > 0 || hdoc_counter > 0)
		return (1);
	return (0);
}

static void	redirect_validations(t_ms *ms, int inf_counter, int out_counter)
{
	if (inf_counter == 0)
	{
		free_matrix(ms->cmds.inf);
		ms->cmds.inf = malloc(2048 * sizeof(char **));
		ms->cmds.inf[0] = NULL;
		ms->cmds.inf_fd = -1;
	}
	if (out_counter == 0)
	{
		free_matrix(ms->cmds.out);
		ms->cmds.out = malloc(2048 * sizeof(char **));
		ms->cmds.out[0] = NULL;
		ms->cmds.inf_fd = -1;
	}
}
