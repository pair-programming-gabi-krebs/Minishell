/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/07 22:59:41 by gcosta-d         ###   ########.fr       */
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
		ms->prompt.line = readline(print_dir(ms));
		free(ms->prompt.prompt); // choose a better place to be
		if (!ms->prompt.line)
		{
			printf("\n");
			free_matrix(ms->lexer.tokens);
			free(ms->prompt.prev_line);
			ft_free(ms);
			exit(1);
		}
		else if (!ft_strncmp(ms->prompt.line, "exit", 5))
		{
			free_matrix(ms->lexer.tokens);
			free(ms->prompt.prev_line);
			ft_free(ms);
			exit(1);
		}
		else if (ft_strlen(ms->prompt.line) != 0)
		{
			history(ms, ms->prompt.line);
			ms->lexer.line = ft_strdup(ms->prompt.line);
			lexer(ms);
			parser(ms);
			ft_reset(ms);
		}
		else if (ft_strlen(ms->prompt.line) == 0)
			free(ms->prompt.line);
	}
}

// lc -la -> analise sintatica (por token)
// lc -la wc -l  -> analise semantica (por linha digitada)