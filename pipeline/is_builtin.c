/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:26:20 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/09 20:47:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(t_ms *ms)
{
	char	*cmd;

	cmd = ms->cmds.command[0];
	if ((cmd && !strict_strcmp(cmd, "cd"))
		|| (cmd && !strict_strcmp(cmd, "echo"))
		|| (cmd && !strict_strcmp(cmd, "env"))
		|| (cmd && !strict_strcmp(cmd, "sport"))
		|| (cmd && !strict_strcmp(cmd, "pwd"))
		|| (cmd && !strict_strcmp(cmd, "unset")))
		return (1);
	return (0);
}
