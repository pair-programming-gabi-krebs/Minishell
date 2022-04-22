/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/22 20:14:51 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_special(t_ms *ms, char c);
static int	pre_tokenization(t_ms *ms, int i);
static int	handle_next_special_bytes(t_ms *ms, int i);
static int	handle_quote(t_ms *ms, int i, char character);
static void	make_substr_and_increment(t_ms *ms, int i, int len);

void	pre_token(t_ms *ms)
{
	int		i;

	i = 0;
	ms->tk.j = 0;
	ms->tk.k = 0;
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

static int	pre_tokenization(t_ms *ms, int i)
{
	make_substr_and_increment(ms, i, i - ms->tk.k);
	if (ms->prompt.line[i] == ms->prompt.line[i + 1])
		i = handle_next_special_bytes(ms, i);
	else if (ms->prompt.line[i] == DOUBLE_QUOTE || \
		ms->prompt.line[i] == SINGLE_QUOTE)
		i  = handle_quote(ms, i, ms->prompt.line[i]);
	make_substr_and_increment(ms, i, ms->tk.len);
	return (i);
}

static void make_substr_and_increment(t_ms *ms, int i, int len)
{
	ms->tk.mtx[ms->tk.j] = ft_substr(ms->prompt.line, ms->tk.k, len);
	printf("ms->tk.mtx[%d] = %s\n\n", ms->tk.j, ms->tk.mtx[ms->tk.j]);
	ms->tk.j++;
	ms->tk.k = i;
}

static int	handle_next_special_bytes(t_ms *ms, int i)
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

static int	handle_quote(t_ms *ms, int i, char chr)
{
	printf("i before while %d\n", i);
	while (ms->prompt.line[i + 1] != chr)
		i++;
	printf("i after while %d\n", i);
	return (i);
}
