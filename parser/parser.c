/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:33:50 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/07 22:09:14 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parser(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->lexer.tokens[i])
	{
		printf("TOKEN: %s\n", ms->lexer.tokens[i]);
		if (ms->lexer.tokens[i][0] == '>' && ms->lexer.tokens[i][1] == '>')
			printf("Append\n");
		else if (ms->lexer.tokens[i][0] == '>')
			printf("Outfile\n");
		else if (ms->lexer.tokens[i][0] == '<' && ms->lexer.tokens[i][1] == '<')
			printf("Here_doc\n");
		else if (ms->lexer.tokens[i][0] == '<')
			printf("Infile\n");
		else if (ms->lexer.tokens[i][0] == '|')
			printf("Pipe\n");
		else if (ms->lexer.tokens[i][0] == '$')
			printf("Arg\n");
		else
			printf("Word\n");
		i++;
	}

}
