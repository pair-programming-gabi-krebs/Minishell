/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/17 22:15:28 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pipex(t_ms *ms)
{
	int	i;

	parse_env(ms);
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		if (i > 0)
		{
			dup2(ms->cmds.fd[0], STDIN_FILENO);
			close(ms->cmds.fd[0]);
		}
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		build_cmd_table(ms);
		if (is_builtin(ms))
		{
			exec_builtin(ms);
			i++;
		}
		else
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
				i++;
			}
		}
	}
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	close(ms->cmds.fd[0]);
	close(ms->cmds.fd[1]);
}
