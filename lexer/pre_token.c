/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/27 00:15:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	pre_tokenization(t_ms *ms, int i);

void	pre_token(t_ms *ms)
{
	int		i;

	i = 0;
	ms->tk.j = 0;
	ms->tk.k = 0;
	ms->tk.len = 0;
	ms->tk.mtx = malloc(10 * sizeof(char **));
	while (ms->prompt.line[i])
	{
		while (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]))
			i++;
		i = pre_tokenization(ms, i);
		while (ms->prompt.line[i] && is_special(ms, ms->prompt.line[i]))
			i++;
		i = pre_tokenization(ms, i);
	}
}

static int	pre_tokenization(t_ms *ms, int i)
{
	char	*str;
	char	*strdup;

	strdup = ft_strdup(ms->prompt.line);
	strdup[i] = '\0';

	str = ft_substr(strdup, ms->tk.k, ft_strlen(strdup));
	ms->tk.mtx[ms->tk.j] = ft_strdup(str);
	printf("ms->tk.mtx[%d]: %s\n\n", ms->tk.j, ms->tk.mtx[ms->tk.j]);

	ms->tk.j++;
	ms->tk.k = i;

	free(str);
	free(strdup);
	return (i);
}
