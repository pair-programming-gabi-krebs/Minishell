/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:58:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/06 20:27:02 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	put_space_between(t_ms *ms, int i);
static int	jump_quotes(t_ms *ms, int i);

void	check_special_tokens(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->tk.line[i])
	{
		if (ms->tk.line[i] == DOUBLE_QUOTE || ms->tk.line[i] == SINGLE_QUOTE)
		{
			i = jump_quotes(ms, i);
			if (i == -1)
				break ;
		}
		else if (is_special(ms, ms->tk.line[i]))
		{
			if (ms->tk.line[i + 1]
				&& is_special(ms, ms->tk.line[i + 1])
				&& ms->tk.line[i] != ms->tk.line[i + 1])
				put_space_between(ms, i);
		}
		i++;
	}
}

static void	put_space_between(t_ms *ms, int i)
{
	char	*first_half;
	char	*last_half;

	first_half = ft_strdup(ms->tk.line);
	first_half[i + 1] = ' ';
	first_half[i + 2] = '\0';
	last_half = ft_substr(ms->tk.line, i + 1, ft_strlen(ms->tk.line));
	free(ms->tk.line);
	ms->tk.line = ft_strjoin(first_half, last_half);
	free(first_half);
	free(last_half);
}

static int	jump_quotes(t_ms *ms, int i)
{
	int		index;
	char	chr;

	chr = ms->tk.line[i];
	index = i + 1;
	while (ms->tk.line[index] && ms->tk.line[index] != chr)
		index++;
	if (ms->tk.line[index] && ms->tk.line[index + 1])
		return (index + 1);
	else
		return (-1);
}
