/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/09 22:10:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(t_ms *ms, int i)
{
	char	*cmd;

	cmd = ms->cmds.command[0];
	resolve_dups_infile(ms, i);
	resolve_dups_outfile(ms, i);
	if (!strict_strcmp(cmd, "cd"))
		cd(ms);
	else if (!strict_strcmp(cmd, "echo"))
		echo(ms);
	else if (!strict_strcmp(cmd, "env"))
		env(ms);
	else if (!strict_strcmp(cmd, "export"))
		export(ms, ms->cmds.command[1]);
	else if (!strict_strcmp(cmd, "pwd"))
		pwd();
	else if (!strict_strcmp(cmd, "unset"))
		unset(ms, ms->cmds.command[1]);
	ms->cmds.aux_fd = ms->cmds.fd[0];
	//close(ms->cmds.fd[1]);
}
