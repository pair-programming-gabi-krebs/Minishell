/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/15 00:48:20 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_commands(t_ms *ms)
{
	ft_init_sigaction(ms, handle_child_sig_int, SIGINT);
	ft_init_sigaction(ms, handle_child_sig_quit, SIGQUIT);
	ms->cmds.file_path = ft_strdup(command_finder(ms));
	if (!ms->cmds.file_path)
	{
		printf("%s: command not found", ms->cmds.command[0]);
		ft_exit(ms, 127);
	}
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
		ft_exit(ms, 1);
}
