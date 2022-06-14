/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process_and_exec_cmd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:24:14 by lkrebs-l          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/13 23:16:14 by gcosta-d         ###   ########.fr       */
=======
/*   Updated: 2022/06/13 22:09:34 by lkrebs-l         ###   ########.fr       */
>>>>>>> fe69493bd797e0e5077b04b396ca50fcadbf69c1
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	create_process_and_exec_cmd(t_ms *ms, int i)
{
	if (!is_cmd(ms))
		return ;
	resolve_dups_infile(ms, i);
	resolve_dups_outfile(ms, i);
	ms->cmds.pid = fork();
	if (ms->cmds.pid == -1)
		ft_exit(ms, 1);
	if (ms->cmds.pid == 0)
	{
		ft_init_sigaction(ms, handle_child_sig_int, SIGINT);
		ft_init_sigaction(ms, handle_child_sig_quit, SIGQUIT);
		exec_commands(ms);
	}
	else
	{
		// checkar por erro no waitpid **
		waitpid(ms->cmds.pid, &ms->cmds.exit_status, 0);
		if (WIFEXITED(ms->cmds.exit_status))
			ms->cmds.exit_status = WEXITSTATUS(ms->cmds.exit_status);
		else if (WIFSIGNALED(ms->cmds.exit_status))
			ms->cmds.exit_status = WTERMSIG(ms->cmds.exit_status) + 128;
		ms->cmds.aux_fd = ms->cmds.fd[0];
	}
}

static int	is_cmd(t_ms *ms)
{
	if (!ms->cmds.command[0])
		return (0);
	return (1);
}