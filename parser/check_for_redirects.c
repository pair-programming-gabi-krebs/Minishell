/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/13 23:55:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	check_redirect_count(t_ms *ms);
static void	check_for_redirects_and_here_doc(t_ms *ms, int i);
static void	check_redirect_count(t_ms *ms);

int	check_for_redirects(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[i])
	{
		check_for_redirects_and_here_doc(ms, i);
		i++;
	}
	check_redirect_count(ms);
	if (ms->parser.inf_count > 0 || ms->parser.out_count > 0 || \
		ms->parser.hdoc_count > 0)
		return (1);
	return (0);
}

static void	check_for_redirects_and_here_doc(t_ms *ms, int i)
{
	if (!strict_strcmp(ms->cmds.command[i], "<<") && ms->cmds.command[i + 1])
	{
		ms->cmds.limiter = ms->cmds.command[i + 1];
		here_doc(ms);
		ms->parser.hdoc_count++;
	}
	else if (!strict_strcmp(ms->cmds.command[i], ">>")
		&& ms->cmds.command[i + 1])
	{
		get_redirect_name(ms, ms->cmds.out, i, ms->parser.out_count);
		ms->parser.out_count++;
		ms->cmds.append_flag = 1;
	}
	else if (ms->cmds.command[i][0] == '<')
	{
		get_redirect_name(ms, ms->cmds.inf, i, ms->parser.inf_count);
		ms->parser.inf_count++;
	}
	else if (ms->cmds.command[i][0] == '>')
	{
		get_redirect_name(ms, ms->cmds.out, i, ms->parser.out_count);
		ms->parser.out_count++;
	}
}

static void	check_redirect_count(t_ms *ms)
{
	if (ms->parser.inf_count == 0)
	{
		free_matrix(ms->cmds.inf);
		ms->cmds.inf = malloc(2048 * sizeof(char **));
		ms->cmds.inf[0] = NULL;
		ms->cmds.inf_fd = -1;
	}
	if (ms->parser.out_count == 0)
	{
		free_matrix(ms->cmds.out);
		ms->cmds.out = malloc(2048 * sizeof(char **));
		ms->cmds.out[0] = NULL;
		ms->cmds.inf_fd = -1;
	}
}
