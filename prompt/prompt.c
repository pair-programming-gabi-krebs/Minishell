/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/30 21:20:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define clear() printf("\033[H\033[J")

void	prompt(t_minishell *minishell)
{
	char *line;

	clear();
	while(1)
	{
		line = readline(print_dir(minishell));
		if (ft_strlen(line) != 0)
			history(line);
	}
	free(minishell->prompt.prompt);
}
