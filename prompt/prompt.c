/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/06 19:59:52 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear(void)
{
	printf("\033[H\033[J");
}

void	prompt(t_ms *ms)
{
	char	*line;

	clear();
	while (1)
	{
		sigaction(SIGINT, &ms->signal.sig, NULL);
		line = readline(print_dir(ms));
		free(ms->prompt.prompt); // choose a better place to be
		if (!line)
		{
			printf("\n");
			// it also needs to disalocate all the memory
			exit(1);
		}
		else if (!ft_strncmp(line, "exit", 5))
		{
			exit(1); // we should implement our own exit function
		}
		else if (ft_strlen(line) != 0)
		{
			history(line);
			ms->lexer.line = ft_strdup(line);
			lexer(ms);
			free(ms->lexer.line);
			free(line);
		}
		else if (ft_strlen(line) == 0)
			free(line);
	}
	free(ms->prompt.prompt);
}
