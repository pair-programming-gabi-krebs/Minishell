/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/24 21:31:21 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(t_ms *ms)
{
	int	has_nl;
	int	i;

	has_nl = 1;
	if (!ft_strncmp(ms->cmds.command[1], "-n", ft_strlen(ms->cmds.command[1])))
		has_nl = 0;
	i = 1;
	while (ms->cmds.command[i])
	{
		if (has_nl)
			printf("%s\n", ms->cmds.command[i]);
		else if (ms->cmds.command[i + 1])
			printf("%s", ms->cmds.command[i + 1]);
		i++;
	}
}
