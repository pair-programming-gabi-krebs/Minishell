/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/27 02:47:27 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	init(t_ms *ms);
static void	exit_pipeline(t_ms *ms);

void	pipex(t_ms *ms)
{
	int	i;

	init(ms);
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		build_cmd_table(ms);
		if (!handle_redirects(ms) && ms->parser.pipes_qtn == 0)
		{
			reset_cmd_table(ms);
			exit_pipeline(ms);
			return ;
		}
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms, 1);
		if (is_builtin(ms))
			exec_builtin(ms, i);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	exit_pipeline(ms);
}

static void	init(t_ms *ms)
{
	parse_env(ms);
	ms->cmds.stin = dup(STDIN_FILENO);
	ms->cmds.stout = dup(STDOUT_FILENO);
}

static void	exit_pipeline(t_ms *ms)
{
	reset_std_fds(ms);
	end_pipeline(ms);
}
