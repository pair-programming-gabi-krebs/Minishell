/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:30:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/13 21:45:55 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	tokenizer_common_case(t_ms *ms, int c, int i);

void	tokenizer(t_ms *ms)
{
	size_t	i;
	int		c;

	i = 0;
	while (ms->lexer.line[i] && i < ft_strlen(ms->lexer.line))
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
			i = tokenizer_common_case(ms, c, i);
		}
		if (!ms->lexer.line[i])
			break ;
		i++;
	}
	ms->lexer.tokens[ms->lexer.i_token] = NULL;
}

static int	tokenizer_common_case(t_ms *ms, int c, int i)
{
	while (ms->lexer.line[i] != FT_SPACE && ms->lexer.line[i])
		i++;
	ms->lexer.tokens[ms->lexer.i_token] = ft_substr(ms->lexer.line, c, i - c);
	ms->lexer.i_token++;
	return (i);
}
