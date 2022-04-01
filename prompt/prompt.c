/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/31 21:44:39 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear(void)
{
	printf("\033[H\033[J");
}

void	prompt(t_minishell *minishell)
{
	char *line;

	clear();
	while(1)
	{
		line = readline(print_dir(minishell));
		if (ft_strlen(line) != 0)
		{
			history(line);
			minishell->lexer.line = ft_strdup(line);
			lexer(minishell);
		}
	}
	free(minishell->prompt.prompt);
}
