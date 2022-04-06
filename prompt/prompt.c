/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/06 20:27:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear(void)
{
	printf("\033[H\033[J");
}

void	prompt(t_ms *ms)
{
	clear();
	while (1)
	{
		sigaction(SIGINT, &ms->signal.sig, NULL);
		ms->prompt.line = readline(print_dir(ms));
		free(ms->prompt.prompt); // choose a better place to be
		if (!ms->prompt.line)
		{
			printf("\n");
			// it also needs to disalocate all the memory
			exit(1);
		}
		else if (!ft_strncmp(ms->prompt.line, "exit", 5))
		{
			exit(1); // we should implement our own exit function
		}
		else if (ft_strlen(ms->prompt.line) != 0)
		{
			history(ms->prompt.line);
			ms->lexer.line = ft_strdup(ms->prompt.line);
			lexer(ms);
			free(ms->lexer.line);
			free(ms->prompt.line);
		}
		else if (ft_strlen(ms->prompt.line) == 0)
			free(ms->prompt.line);
	}
	free(ms->prompt.prompt);
}
