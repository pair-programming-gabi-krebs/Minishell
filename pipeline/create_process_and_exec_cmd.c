/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_and_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:24:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/06 23:32:30 by gcosta-d         ###   ########.fr       */
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
		close(ms->cmds.fd[1]);
		close(ms->cmds.fd[0]);
	}
}
