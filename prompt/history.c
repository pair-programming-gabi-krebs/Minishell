/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/03 21:50:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_str_diff(t_ms *ms, char *line);

void	history(t_ms *ms, char *line)
{
	if (!ms->prompt.prev_line)
		add_history(line);
	else if (is_str_diff(ms, line))
		add_history(line);
	free(ms->prompt.prev_line);
	ms->prompt.prev_line = ft_strdup(line);
}

static int	is_str_diff(t_ms *ms, char *line)
{
	int	a;
	int	b;

	a = ft_strncmp(ms->prompt.prev_line, line, ft_strlen(line));
	b = ft_strncmp(line, ms->prompt.prev_line, ft_strlen(ms->prompt.prev_line));
	if (a || b)
		return (1);
	return (0);
}
