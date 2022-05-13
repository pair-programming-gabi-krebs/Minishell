/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/12 20:45:25 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(t_ms *ms)
{
	int	has_nl;
	int	i;

	has_nl = 1;
	if (!ft_strncmp(ms->lexer.tokens[1], "-n", ft_strlen(ms->lexer.tokens[1])))
		has_nl = 0;
	i = 0;
	while (ms->lexer.tokens[++i] && !is_special(ms, ms->lexer.tokens[i][0]))
	{
		if (has_nl)
			printf("%s\n", ms->lexer.tokens[i]);
		else
			printf("%s", ms->lexer.tokens[i + 1]);
	}
}

// echo teste "teste"

// >outfile echo "teste"| tr ' ' a

// >
// outfile
// echo
// teste|
// tr
// ' '
// a

// "l"s

/*
	[x] Verificar se há -n
	[ ] Verificar se há $
	[ ] Verificar se há single quote
	[ ] Verificar se há double quote
*/