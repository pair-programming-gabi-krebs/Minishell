/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:29:26 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/23 20:44:58 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_dir_not_found(t_ms *ms, int return_chdir)
{
	if (return_chdir == -1)
	{
		perror("");
		ms->cmds.exit_status = 1;
		return (1);
	}
	return (0);
}

int	check_args(t_ms *ms)
{
	int	i;

	i = 1;
	while (ms->cmds.command[i])
		i++;
	if (i > 2)
		return (1);
	return (0);
}

void	handle_too_many_arguments(t_ms *ms)
{
	write(1, "cd: too many arguments\n", 23);
	ms->cmds.exit_status = 1;
}

char	*handle_home_dir(t_ms *ms, char *path)
{
	char	*aux1;
	char	*aux2;

	aux1 = ft_strdup(ms->cmds.command[1]);
	aux2 = ft_strtrim(aux1, "~");
	path = ft_strjoin(getenv("HOME"), aux2);
	free(aux1);
	free(aux2);
	return (path);
}
