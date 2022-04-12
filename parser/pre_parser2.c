/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:58:35 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/11 22:55:08 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	find_last_char(char *string, char c);

void	pre_parser2(t_ms *ms)
{
	int	i;
	int	first_quote;
	int	last_quote;
	int	char_index;
	char	**split;
	char	*parsed_line;

	i = 0;
	while (i < ft_mtxlen(ms->lexer.tokens))
	{
		first_quote = strichar(ms->lexer.tokens[i], 0, DOUBLE_QUOTE);
		last_quote = find_last_char(ms->lexer.tokens[i], DOUBLE_QUOTE);
		char_index = strichar(ms->lexer.tokens[i], 0, '<');
		if (first_quote == -1 || char_index < first_quote || char_index > last_quote)
		{
			// substring do primeiro byte até o um byte antes do pipe
			split[0] = ft_substr(ms->lexer.tokens[i], 0, char_index);
			parsed_line = ft_substr(ms->lexer.tokens[i], 0, char_index);
			for(int j = 0; j < ft_mtxlen(split); j++)
				printf("token: %s\n", split[j]);
		}
		i++;
	}
}

// "ls<infile" |wc -l

static int	find_last_char(char *string, char c)
{
	int	last;
	int	next;

	next = 0;
	last = -1;
	while (next != -1)
	{
		next = strichar(string, next + 1, c);
		if (next != -1)
			last = next;
	}
	return (last);
}
