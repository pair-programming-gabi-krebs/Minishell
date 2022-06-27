/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntatic_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:59:26 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/27 02:47:05 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_next_token(t_ms *ms, int i);
static int	check_token_for_redirects(t_ms *ms, int i);

int	syntatic_analysis(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.i_token)
	{
		if (ms->lexer.flag_quote[i] == '.' && !check_token_for_redirects(ms, i))
			return (0);
		i++;
	}
	return (1);
}

static int	check_token_for_redirects(t_ms *ms, int i)
{
	if (ms->lexer.tokens[i][0] == '<' || ms->lexer.tokens[i][0] == '>')
	{
		if (!check_next_token(ms, i + 1))
		{
			printf("syntax error near unexpected token `%s'\n", \
				ms->lexer.tokens[i]);
			return (0);
		}
	}
	return (1);
}

static int	check_next_token(t_ms *ms, int i)
{
	int	j;

	j = 0;
	while (ms->lexer.tokens[i] && ms->lexer.tokens[i][j])
	{
		if (is_special(ms, ms->lexer.tokens[i][j]) && \
			ms->lexer.tokens[i][j] != '$')
			return (0);
		j++;
	}
	return (1);
}
