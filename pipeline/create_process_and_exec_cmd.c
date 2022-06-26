/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_and_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:24:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/26 19:26:23 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_cmd(t_ms *ms);

void	create_process_and_exec_cmd(t_ms *ms, int i)
{
	resolve_dups_infile(ms, i);
	resolve_dups_outfile(ms, i);
	if (!is_cmd(ms))
	{
		ms->cmds.aux_fd = ms->cmds.fd[0];
		return ;
	}
	ft_init_sigaction(ms, SIG_IGN, SIGINT);
	ms->cmds.pid = fork();
	if (ms->cmds.pid == -1)
		ft_exit(ms, 1);
	if (ms->cmds.pid == 0)
		exec_commands(ms);
	else
	{
		ft_waitpid(ms, ms->cmds.pid);
		ms->cmds.aux_fd = ms->cmds.fd[0];
		close(ms->cmds.fd[1]);
	}
}

static int	is_cmd(t_ms *ms)
{
	if (!ms->cmds.command[0])
		return (0);
	return (1);
}
