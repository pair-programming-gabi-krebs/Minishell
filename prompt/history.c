/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:22:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/30 23:17:17 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	history(char *line)
{
	static char	*previous_line = NULL;

	if (!previous_line)
	{
		previous_line = ft_strdup(line);
		add_history(line);
	}
	if (ft_strncmp(previous_line, line, ft_strlen(line))
		|| ft_strncmp(line, previous_line, ft_strlen(previous_line)))
		add_history(line);
	previous_line = line;
}
