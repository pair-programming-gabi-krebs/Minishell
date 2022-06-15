/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/14 21:49:25 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	reset_std_fds(t_ms *ms);

void	pipex(t_ms *ms)
{
	int	i;

	parse_env(ms);
	ms->cmds.stin = dup(STDIN_FILENO);
	ms->cmds.stout = dup(STDOUT_FILENO);
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		build_cmd_table(ms);
		handle_redirects(ms);
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms, 1);
		if (is_builtin(ms))
			exec_builtin(ms, i);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	reset_std_fds(ms);
	end_pipeline(ms);
}

static void	reset_std_fds(t_ms *ms)
{
	dup42(ms->cmds.stin, STDIN_FILENO);
	dup42(ms->cmds.stout, STDOUT_FILENO);
}
