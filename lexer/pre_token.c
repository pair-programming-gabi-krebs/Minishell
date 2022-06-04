/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 22:12:30 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	pre_token_init(t_ms *ms);

void	pre_token(t_ms *ms)
{
	int	i;

	pre_token_init(ms);
	i = 0;
	while (ms->prompt.line[i])
	{
		while (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]))
		{
			i++;
			if (!ms->prompt.line[i])
				break ;
		}
		pre_tokenization(ms, i);
		while (ms->prompt.line[i] && is_special(ms, ms->prompt.line[i]))
		{
			i++;
			if (!ms->prompt.line[i])
				break ;
		}
		pre_tokenization(ms, i);
	}
	ms->tk.mtx[ms->tk.j] = '\0';
	line_formater(ms);
	free_matrix(ms->tk.mtx);
}

static void	pre_token_init(t_ms *ms)
{
	ms->tk.j = 0;
	ms->tk.k = 0;
	ms->tk.len = 0;
	ms->tk.mtx = malloc(100 * sizeof(char **));
	ms->tk.line = NULL;
}
