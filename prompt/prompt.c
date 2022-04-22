/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:39:38 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/21 21:02:04 by lkrebs-l         ###   ########.fr       */
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
		if (!ms->prompt.line || !ft_strncmp(ms->prompt.line, "exit", 5))
			ft_exit(ms);
		else if (ft_strlen(ms->prompt.line) != 0)
			valid_input(ms);
		else if (ft_strlen(ms->prompt.line) == 0)
			ft_free(ms);
	}
}
