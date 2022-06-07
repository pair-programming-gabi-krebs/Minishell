/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/06 22:11:04 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pipex(t_ms *ms)
{
	int	i;

	parse_env(ms);
	ms->cmds.stin = -1;
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		build_cmd_table(ms);
		if (!handle_redirects(ms))
			return ;
		resolve_dups_infile(ms, i);
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		if (is_builtin(ms))
			exec_builtin(ms, i);
		else
			create_process_and_exec_cmd(ms, i);
		reset_cmd_table(ms);
		i++;
	}
	dup2(ms->cmds.stin, STDIN_FILENO);
	end_pipeline(ms);
}
