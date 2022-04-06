/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/05 22:23:57 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clear(void)
{
	printf("\033[H\033[J");
}

static void sigint_handler(int number)
{
	(void)number;
	write(2, "\n", 1);
	close(STDIN_FILENO);
	open(STDIN_FILENO, O_RDWR, 0777);
	// fprintf(stderr, "Ctrl-C (%d)\n", signum);
}

void	prompt(t_ms *ms)
{
	char				*line;
	struct sigaction	sig;

	clear();
	sig.sa_handler = sigint_handler;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGINT, &sig, NULL);
	while(1)
	{
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
