/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:57:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/13 23:03:40 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_path_bin(char *command);

char	*command_finder(t_ms *ms)
{
	int		i;
	int		check;
	char	*path;
	char	*cmd;

	if (!ms->cmds.command[0])
	{
		return (NULL);
	}
	if (is_path_bin(ms->cmds.command[0]))
		return (ms->cmds.command[0]);
	i = 0;
	if (!ms->cmds.bin)
		return (NULL);
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

static int	is_path_bin(char *command)
{
	int	is_path;

	is_path = 0;
	if (command && !access(command, F_OK))
		is_path = 1;
	return (is_path);
}
