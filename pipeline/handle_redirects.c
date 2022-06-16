/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:14:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/16 17:59:14 by gcosta-d         ###   ########.fr       */
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
	int	pid;

	i = 0;
	inf_count = ft_mtxlen(ms->cmds.inf);
	while (i < inf_count)
	{
		if (ms->cmds.hdoc_counter)
		{
			ms->cmds.hdoc_flag = 1;
			ft_init_sigaction(ms, SIG_IGN, SIGINT);
			pid = fork();
			if (pid == 0)
				here_doc(ms);
			else
			{
				waitpid(pid, &ms->cmds.exit_status, 0);
				if (WIFEXITED(ms->cmds.exit_status))
					ms->cmds.exit_status = WEXITSTATUS(ms->cmds.exit_status);
				else if (WIFSIGNALED(ms->cmds.exit_status))
					ms->cmds.exit_status = WTERMSIG(ms->cmds.exit_status) + 128;
			}
		}
		else
			ms->cmds.inf_fd = open(ms->cmds.inf[i], O_RDONLY, 0777);
		if (ms->cmds.inf_fd == -1 && ms->cmds.hdoc_flag == 0)
		{
			perror(ms->cmds.inf[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		else if (ms->cmds.hdoc_flag == 1)
		{
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
			perror(ms->cmds.out[i]);
			ms->cmds.exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
