/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:27:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/12 21:50:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	count_pipes(t_ms *ms);

void	pipeline(t_ms *ms)
{
	count_pipes(ms);
	pipex(ms);
}

static void	count_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.i_token)
	{
		if (ms->lexer.tokens[i][0] == '|')
			ms->parser.pipes_qtn++;
		i++;
	}
}
