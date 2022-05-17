/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/16 22:03:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(t_ms *ms)
{
	char	*cmd;

	cmd = ms->cmds.command[0];
	if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		cd(ms);
	else if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		echo(ms);
	else if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
		env(ms);
	else if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		export(ms, ms->cmds.command[1]);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		pwd();
	else if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
		unset(ms, ms->cmds.command[1]);
}
