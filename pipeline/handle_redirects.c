/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 19:41:07 by gcosta-d         ###   ########.fr       */
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
		ms->cmds.inf_fd = open(ms->cmds.inf[i], O_RDONLY, 0777);
		if (ms->cmds.inf_fd == -1)
		{
			printf("inf file does not exists :(\n");
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
		ms->cmds.out_fd = open(ms->cmds.out[i], O_WRONLY | O_CREAT | O_TRUNC, \
			0777);
		if (ms->cmds.out_fd == -1)
		{
			printf("out file does not exists :(\n");
			return (0);
		}
		i++;
	}
	return (1);
}
