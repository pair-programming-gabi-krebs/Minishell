/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/26 19:37:38 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_commands(t_ms *ms)
{
	char	*check_command_finder;

	ft_init_sigaction(ms, handle_child_sig_int, SIGINT);
	ft_init_sigaction(ms, handle_child_sig_quit, SIGQUIT);
	check_command_finder = command_finder(ms);
	if (check_command_finder)
		ms->cmds.file_path = ft_strdup(command_finder(ms));
	else
		ms->cmds.file_path = command_finder(ms);
	if (!ms->cmds.file_path)
	{
		ft_putstr_fd(ms->cmds.command[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_exit(ms, 127);
	}
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
	{
		perror("");
		ft_exit(ms, 1);
	}
}
