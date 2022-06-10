/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/09 21:37:04 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_commands(t_ms *ms)
{
	ms->cmds.file_path = command_finder(ms);
	if (!ms->cmds.file_path)
	{
		printf("%s: command not found", ms->cmds.command[0]);
		ft_exit(ms);
	}
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
	{
		dprintf(2, "exec fail\n");
		ft_exit(ms);
	}
}
