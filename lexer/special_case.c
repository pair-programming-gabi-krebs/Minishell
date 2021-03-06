/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:18:00 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/15 20:08:06 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	special_case(t_ms *ms, char quote, int index)
{
	int	start_quote;

	start_quote = index;
	while (ms->lexer.line[index] && ms->lexer.line[index + 1]
		&& ms->lexer.line[index + 1] != quote)
		index++;
	index++;
	if ((ms->lexer.line[index] && ms->lexer.line[index + 1]) \
		&& ms->lexer.line[index + 1] == FT_SPACE)
	{
		ms->lexer.tokens[ms->lexer.i_token] = ft_substr(ms->lexer.line, \
			start_quote, (index - start_quote) + 1);
	}
	else
	{
		while (ms->lexer.line[index] && ms->lexer.line[index] != FT_SPACE)
			index++;
		ms->lexer.tokens[ms->lexer.i_token] = ft_substr(ms->lexer.line, \
			start_quote, index - start_quote);
	}
	ms->lexer.i_token++;
	return (index);
}
