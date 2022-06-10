/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/09 22:37:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (!handle_redirects(ms))
			return ;
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		if (is_builtin(ms))
			exec_builtin(ms, i);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	dup42(ms->cmds.stin, STDIN_FILENO);
	dup42(ms->cmds.stout, STDOUT_FILENO);
	end_pipeline(ms);
}
