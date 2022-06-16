/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/16 19:55:46 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	open_inf_redirects(t_ms *ms);
static int	open_out_redirects(t_ms *ms);
static void	init_child_here_doc(t_ms *ms, int pid);

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
	int	pid;

	i = 0;
	inf_count = ft_mtxlen(ms->cmds.inf);
	pid = -1;
	while (i < inf_count)
	{
		if (ms->cmds.hdoc_counter)
			init_child_here_doc(ms, pid);
		else
			ms->cmds.inf_fd = open(ms->cmds.inf[i], O_RDONLY, 0777);
		if (ms->cmds.inf_fd == -1 && ms->cmds.hdoc_flag == 0)
		{
			perror(ms->cmds.inf[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		else if (ms->cmds.hdoc_flag == 1)
			return (0);
		i++;
	}
	return (1);
}

static void	init_child_here_doc(t_ms *ms, int pid)
{
	ms->cmds.hdoc_flag = 1;
	ft_init_sigaction(ms, SIG_IGN, SIGINT);
	pid = fork();
	if (pid == 0)
		here_doc(ms);
	else
		ft_waitpid(ms, pid);
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
			perror(ms->cmds.out[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
