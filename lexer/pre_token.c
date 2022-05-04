/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/03 21:45:40 by lkrebs-l         ###   ########.fr       */
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
		if (is_special(ms, ms->prompt.line[i]))
			i = pre_tokenization(ms, i);
		if (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i])
			&& ms->prompt.line[i + 1] == '\0')
		{
			ms->tk.mtx[ms->tk.j] = ft_substr(ms->prompt.line, \
				ms->tk.k, i - ms->tk.k + 1);
			printf("ms->tk.mtx[%d] = %s\n\n", ms->tk.j, ms->tk.mtx[ms->tk.j]);
		}
		if (ms->prompt.line[i])
			i++;
	}
}

static int	pre_tokenization(t_ms *ms, int i)
{
	make_substr_and_increment(ms, i, i - ms->tk.k);
	if (ms->prompt.line[i] == ms->prompt.line[i + 1])
		i = handle_next_special_bytes(ms, i);
	else if (ms->prompt.line[i] == DOUBLE_QUOTE || \
		ms->prompt.line[i] == SINGLE_QUOTE)
		i = handle_quote(ms, i, ms->prompt.line[i]);
	make_substr_and_increment(ms, i, ms->tk.len);
	return (i);
}
