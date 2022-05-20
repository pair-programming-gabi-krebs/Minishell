/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/19 22:15:39 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_commands(t_ms *ms, int i)
{
	ms->cmds.file_path = command_finder(ms);
	if (ms->cmds.file_path == NULL)
		ft_exit(ms);
	resolve_dups(ms, i);
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
		ft_exit(ms);
}
