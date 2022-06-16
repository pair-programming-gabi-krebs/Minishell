/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:20:31 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/16 19:26:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free(t_ms *ms)
{
	if (ms->lexer.line)
		free(ms->lexer.line);
	free(ms->prompt.prompt);
	if (ms->tk.line)
		free(ms->tk.line);
	free(ms->prompt.line);
	free(ms->prompt.cwd);
	free(msl->cmds.limiter);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}
