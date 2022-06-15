/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/15 20:39:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	open_inf_redirects(t_ms *ms);
static int	open_out_redirects(t_ms *ms);

int	handle_redirects(t_ms *ms)
{
	if (!open_out_redirects(ms))
		return (0);
	if (!open_inf_redirects(ms))
		return (0);
	return (1);
}

static int	open_inf_redirects(t_ms *ms)
{
	int	i;
	int	inf_count;

	i = 0;
	inf_count = ft_mtxlen(ms->cmds.inf);
	while (i < inf_count)
	{
		if (ms->cmds.hdoc_counter)
			here_doc(ms);
		else
			ms->cmds.inf_fd = open(ms->cmds.inf[i], O_RDONLY, 0777);
		if (ms->cmds.inf_fd == -1)
		{
			printf("Minishell: %s: Permission denied", ms->cmds.inf[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

static int	open_out_redirects(t_ms *ms)
{
	int	i;
	int	out_count;

	i = 0;
	out_count = ft_mtxlen(ms->cmds.out);
	while (i < out_count)
	{
		if (ms->cmds.append_flag)
			ms->cmds.out_fd = open(ms->cmds.out[i], \
			O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			ms->cmds.out_fd = open(ms->cmds.out[i], \
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (ms->cmds.out_fd == -1)
		{
			printf("Minishell: %s: Permission denied\n", ms->cmds.out[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
