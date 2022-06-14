/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:26:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/14 01:34:53 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	syntatic_analysis(t_ms *ms);
static int	check_next_token(t_ms *ms, int i);

int	lexer(t_ms *ms)
{
	tokenizer(ms);
	remove_quotes(ms);
	check_expand_var(ms);
	if(!syntatic_analysis(ms))
		return (0);
	return (1);
}

static int	syntatic_analysis(t_ms *ms)
{
	int	i;

	i = 0;
	
	while (i < ms->lexer.i_token)
	{
		if (ms->lexer.tokens[i][0] == '<' || ms->lexer.tokens[i][0] == '>' )
			if (!check_next_token(ms, i + 1))
			{
				printf("syntax error near unexpected token `%s'\n", ms->lexer.tokens[i]);
				return (0);
			}
		i++;
	}
	return (1);
}

static int	check_next_token(t_ms *ms, int i)
{
	int	j;

	j = 0;
	while (ms->lexer.tokens[i][j])
	{
		/* printf("ms->lexer.tokens[i][%d]: %c\n",j, ms->lexer.tokens[i][j]); */
		if (!ft_isalnum(ms->lexer.tokens[i][j]) && ms->lexer.tokens[i][j] != '$')
			return (0);
			/* printf("faiou: %c\n", ms->lexer.tokens[i][j]); */
		j++;
	}
	return (1);
}