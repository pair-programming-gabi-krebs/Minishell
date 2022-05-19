/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/17 23:32:31 by lkrebs-l         ###   ########.fr       */
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
			dup42(ms->cmds.fd[0], STDIN_FILENO);
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		build_cmd_table(ms);
		if (is_builtin(ms))
			exec_builtin(ms);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	end_pipeline(ms);
}
