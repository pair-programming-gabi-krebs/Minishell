/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:14:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/06 21:03:19 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_commands(t_ms *ms, int i)
{
	ms->cmds.file_path = command_finder(ms);
	if (!ms->cmds.file_path)
		ft_exit(ms);
	resolve_dups_outfile(ms, i);
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
	ft_exit(ms);	
}
