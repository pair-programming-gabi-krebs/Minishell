/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/06 23:06:52 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	history(t_ms *ms, char *line)
{
	if (!ms->prompt.prev_line)
	{
		add_history(line);
	}
	else if (ft_strncmp(ms->prompt.prev_line, line, ft_strlen(line))
		|| ft_strncmp(line, ms->prompt.prev_line, ft_strlen(ms->prompt.prev_line)))
		{
			add_history(line);
		}
	free(ms->prompt.prev_line);
	ms->prompt.prev_line = ft_strdup(line);
}
