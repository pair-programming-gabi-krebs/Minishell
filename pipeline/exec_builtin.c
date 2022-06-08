/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/08 18:57:28 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(t_ms *ms, int i)
{
	char	*cmd;

	cmd = ms->cmds.command[0];
	resolve_dups_infile(ms, i);
	resolve_dups_outfile(ms, i);
	if (!extrict_strcmp(cmd, "cd"))
		cd(ms);
	else if (!extrict_strcmp(cmd, "echo"))
		echo(ms);
	else if (!extrict_strcmp(cmd, "env"))
		env(ms);
	else if (!extrict_strcmp(cmd, "export"))
		export(ms, ms->cmds.command[1]);
	else if (!extrict_strcmp(cmd, "pwd"))
		pwd();
	else if (!extrict_strcmp(cmd, "unset"))
		unset(ms, ms->cmds.command[1]);
	//close(ms->cmds.fd[1]);
}
