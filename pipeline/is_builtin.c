/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:26:20 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/17 23:38:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_builtin(t_ms *ms)
{
	char	*cmd;

	cmd = ms->cmds.command[0];
	if ((cmd && !ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		|| (cmd && !ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		|| (cmd && !ft_strncmp(cmd, "env", ft_strlen(cmd)))
		|| (cmd && !ft_strncmp(cmd, "export", ft_strlen(cmd)))
		|| (cmd && !ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		|| (cmd && !ft_strncmp(cmd, "unset", ft_strlen(cmd))))
		return (1);
	return (0);
}
