/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:17:13 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/22 20:17:52 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_special(t_ms *ms, char c)
{
	int	i;

	i = 0;
	while (ms->prompt.special[i])
	{
		if (ms->prompt.special[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void make_substr_and_increment(t_ms *ms, int i, int len)
{
	ms->tk.mtx[ms->tk.j] = ft_substr(ms->prompt.line, ms->tk.k, len);
	printf("ms->tk.mtx[%d] = %s\n\n", ms->tk.j, ms->tk.mtx[ms->tk.j]);
	ms->tk.j++;
	ms->tk.k = i;
}

int	handle_next_special_bytes(t_ms *ms, int i)
{
	char	chr;

	ms->tk.len = 0;
	chr = ms->prompt.line[i];
	while (is_special(ms, ms->prompt.line[i]) && ms->prompt.line[i] == chr)
	{
		ms->tk.len++;
		i++;
	}
	return (i);
}

int	handle_quote(t_ms *ms, int i, char chr)
{
	printf("i before while %d\n", i);
	while (ms->prompt.line[i + 1] != chr)
		i++;
	printf("i after while %d\n", i);
	return (i);
}
