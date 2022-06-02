/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/01 22:36:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	handle_redirects(t_ms *ms);
static int	open_inf_redirects(t_ms *ms);
static int	open_out_redirects(t_ms *ms);

void	pipex(t_ms *ms)
{
	int	i;
	int stin;

	parse_env(ms);
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		if (i >= 0)
		{
			if (i == 0)
				stin = dup(STDIN_FILENO);
			dup42(ms->cmds.fd[0], STDIN_FILENO);
		}
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		build_cmd_table(ms);
		if (!handle_redirects(ms))
			return ;
		if (is_builtin(ms))
			exec_builtin(ms);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	if (ms->parser.pipes_qtn > 0)
		dup2(stin, STDIN_FILENO);
	end_pipeline(ms);
}

static int	handle_redirects(t_ms *ms)
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
		ms->cmds.out_fd = open(ms->cmds.out[i], O_WRONLY | O_CREAT | O_TRUNC , \
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
