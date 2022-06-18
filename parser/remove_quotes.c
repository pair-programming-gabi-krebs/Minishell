/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:53:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/18 12:38:46 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_quotes_from_str(t_ms *ms, int i, char *c);

void	remove_quotes(t_ms *ms)
{
	int	i;

	i = 0;
	ms->lexer.flag_quote = malloc ((ms->lexer.i_token + 1) * sizeof(char));
	while (i < ms->lexer.i_token)
	{
		if (!ft_strchr(ms->lexer.tokens[i], DOUBLE_QUOTE) && \
			!ft_strchr(ms->lexer.tokens[i], SINGLE_QUOTE))
			ms->lexer.flag_quote[i] = '.';
		if (ft_strchr(ms->lexer.tokens[i], SINGLE_QUOTE))
		{
			ms->lexer.flag_quote[i] = SINGLE_QUOTE;
			remove_quotes_from_str(ms, i, "\'");
		}
		if (ft_strchr(ms->lexer.tokens[i], DOUBLE_QUOTE))
		{
			ms->lexer.flag_quote[i] = DOUBLE_QUOTE;
			remove_quotes_from_str(ms, i, "\"");
		}
		i++;
	}
	ms->lexer.flag_quote[i] = '\0';
}

static void	remove_quotes_from_str(t_ms *ms, int i, char *c)
{
	char	*aux;
	int		char_index;

	aux = ft_strdup(ms->lexer.tokens[i]);
	free(ms->lexer.tokens[i]);
	ms->lexer.tokens[i] = ft_strtrim(aux, c);
	free(aux);
	char_index = 0;
	while (ft_strchr(ms->lexer.tokens[i], *c))
	{
		char_index = strichar(ms->lexer.tokens[i], 0, *c);
		while (ms->lexer.tokens[i][char_index])
		{
			ms->lexer.tokens[i][char_index] = \
			ms->lexer.tokens[i][char_index + 1];
			char_index++;
		}
	}
}
