/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntatic_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:49:51 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/09 21:43:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_word(char *str);

int	syntatic_analysis(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.i_token)
	{
		if (!ft_strncmp(ms->lexer.tokens[i], "<", ft_strlen("<")))
		{
			if (ms->lexer.tokens[i + 1] && !is_word(ms->lexer.tokens[i + 1]))
				printf("hah! worked\n");
			else
				printf("hmm, didn't work :(\n");
			break ;
		}
		i++;
	}
	return (1);
}

static int	is_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (1);
		i++;
	}
	return (0);
}