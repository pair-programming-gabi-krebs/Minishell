/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/12 22:00:20 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	normalize(t_ms *ms, char character, char *str)
{
	char	**split;
	char	*prev;
	char	*aux;
	int		i;

	split = ft_split(ms->prompt.line, character);
	prev = ft_strdup(split[0]);
	i = 1;
	while (i < ft_mtxlen(split))
	{
		aux = ft_strjoin(prev, str);
		free(prev);
		prev = ft_strdup(aux);
		free(aux);
		aux = ft_strjoin(prev, split[i]);
		free(prev);
		prev = ft_strdup(aux);
		free(aux);
		i++;
	}
	free(ms->prompt.line);
	ms->prompt.line = ft_strdup(prev);
	free_matrix(split);
	free(prev);
}

void	pre_token(t_ms *ms)
{
	if (ft_strchr(ms->prompt.line, '|'))
		normalize(ms, '|', " | ");
	if (ft_strchr(ms->prompt.line, '<'))
		normalize(ms, '<', " < ");
	if (ft_strchr(ms->prompt.line, '>'))
		normalize(ms, '>', " > ");
}
