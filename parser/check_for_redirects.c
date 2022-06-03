/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 20:40:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	reset_matrix(char **matrix);
static int	redirect_validations(t_ms *ms, int inf_counter, int out_counter);

int	check_for_redirects(t_ms *ms)
{
	int	i;
	int	out_counter;
	int	inf_counter;

	out_counter = 0;
	inf_counter = 0;
	i = 0;
	while (ms->cmds.command[i])
	{
		if (ms->cmds.command[i][0] == '<')
		{
			get_redirect_name(ms, ms->cmds.inf, i, inf_counter);
			inf_counter++;
		}
		else if (ms->cmds.command[i][0] == '>')
		{
			get_redirect_name(ms, ms->cmds.out, i, out_counter);
			out_counter++;
		}
		i++;
	}
	if (redirect_validations(ms, inf_counter, out_counter))
		return (1);
	return (0);
}

static int	redirect_validations(t_ms *ms, int inf_counter, int out_counter)
{
	if (inf_counter == 0)
	{
		reset_matrix(ms->cmds.inf);
		ms->cmds.inf_fd = -1;
	}
	if (out_counter == 0)
	{
		reset_matrix(ms->cmds.out);
		ms->cmds.out_fd = -1;
	}
	if (inf_counter > 0 || out_counter > 0)
		return (1);
	return (0);
}

static void	reset_matrix(char **matrix)
{
	free_matrix(matrix);
	matrix = malloc(2048 * sizeof(char **));
	matrix[0] = NULL;
}
