/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/06 02:20:50 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear(void)
{
	printf("\033[H\033[J");
}

void	prompt(t_ms *ms)
{
	char				*line;

	clear();
	while(1)
	{
		ft_signal(ms);
		line = readline(print_dir(ms));
		if (!line)
		{
			printf("\n");
			exit(1);
		}
		else if (ft_strlen(line) != 0)
		{
			history(line);
			ms->lexer.line = ft_strdup(line);
			lexer(ms);
			free(ms->lexer.line);
		}
	}
	free(ms->prompt.prompt);
}
