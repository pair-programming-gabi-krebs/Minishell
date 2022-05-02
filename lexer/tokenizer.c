/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:30:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/30 23:05:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenizer(t_ms *ms)
{
	size_t	i;
	int		c;

	i = 0;
	while (i < ft_strlen(ms->lexer.line))
	{
		if (ms->lexer.line[i] == SINGLE_QUOTE)
			i = special_case(ms, SINGLE_QUOTE, i);
		else if (ms->lexer.line[i] == DOUBLE_QUOTE)
			i = special_case(ms, DOUBLE_QUOTE, i);
		else if (ms->lexer.line[i] == FT_SPACE)
		{
			i++;
			continue ;
		}
		else
		{
			c = i;
			while (ms->lexer.line[i] != FT_SPACE && ms->lexer.line[i])
				i++;
			ms->lexer.tokens[ms->lexer.i_token] = ft_substr(ms->lexer.line, \
				c, i - c);
			ms->lexer.i_token++;
		}
		i++;
	}
	ms->lexer.tokens[ms->lexer.i_token] = NULL;
}
