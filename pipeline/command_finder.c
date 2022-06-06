/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:57:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/06 20:54:29 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*command_finder(t_ms *ms)
{
	int		i;
	int		check;
	char	*path;
	char	*cmd;

	i = 0;
	while (ms->init.envp[i] && ms->cmds.bin[i])
	{
		path = ft_strjoin(ms->cmds.bin[i], "/");
		cmd = ft_strjoin(path, ms->cmds.command[0]);
		check = access(cmd, F_OK);
		if (check == 0)
		{
			free(path);
			return (cmd);
		}
		free(path);
		free(cmd);
		i++;
	}
	return (NULL);
}
