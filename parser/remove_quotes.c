/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:53:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/10 20:01:18 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_quotes_from_str(t_ms *ms, int i, char *c);

void	remove_quotes(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.i_token)
	{
		if (ft_strchr(ms->lexer.tokens[i], SINGLE_QUOTE))
		{
			ms->lexer.flag_quote = SINGLE_QUOTE;
			remove_quotes_from_str(ms, i, "\'");
		}
		if (ft_strchr(ms->lexer.tokens[i], DOUBLE_QUOTE))
		{
			ms->lexer.flag_quote = DOUBLE_QUOTE;
			remove_quotes_from_str(ms, i, "\"");
		}
		i++;
	}
}

static void	remove_quotes_from_str(t_ms *ms, int i, char *c)
{
	char	*aux;

	aux = ft_strdup(ms->lexer.tokens[i]);
	free(ms->lexer.tokens[i]);
	ms->lexer.tokens[i] = ft_strtrim(aux, c);
	free(aux);
}
