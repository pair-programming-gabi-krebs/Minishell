/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 19:21:05 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	handle_redirects(t_ms *ms);
static int	open_inf_redirects(t_ms *ms);
static int	open_out_redirects(t_ms *ms);

void	pipex(t_ms *ms)
{
	int	i;
	int	stin;

	parse_env(ms);
	stin = -1;
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		build_cmd_table(ms);
		if (!handle_redirects(ms))
			return ;
		if (i == -1 && ms->cmds.inf_fd != -1)
			stin = dup_infile(ms, stin, i);
		else if (i >= 0 && ms->cmds.inf_fd != -1)
			stin = dup_infile(ms, stin, i);
		else if (i >= 0)
		{
			stin = dup_infile(ms, stin, i);
			if (ms->cmds.inf_fd == -1)
				dup42(ms->cmds.fd[0], STDIN_FILENO);
			else
				dup42(ms->cmds.inf_fd, STDIN_FILENO);
		}
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		if (is_builtin(ms))
			exec_builtin(ms);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	dup2(stin, STDIN_FILENO);
	end_pipeline(ms);
}
