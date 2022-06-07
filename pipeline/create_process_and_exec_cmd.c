/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_and_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:24:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/07 19:39:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_process_and_exec_cmd(t_ms *ms, int i)
{
	ms->cmds.pid = fork();
	if (ms->cmds.pid == -1)
		ft_exit(ms);
	if (ms->cmds.pid == 0)
		exec_commands(ms, i);
	else
	{
		waitpid(ms->cmds.pid, &ms->cmds.exit_status, 0);
		if (WIFEXITED(ms->cmds.exit_status))
			ms->cmds.exit_status = WEXITSTATUS(ms->cmds.exit_status);
		else if (WIFSIGNALED(ms->cmds.exit_status))
			ms->cmds.exit_status = WTERMSIG(ms->cmds.exit_status) + 128;
		close(ms->cmds.fd[1]);
	}
}
