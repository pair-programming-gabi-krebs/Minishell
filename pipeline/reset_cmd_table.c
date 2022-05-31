/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:50:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/30 23:56:37 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	reset_cmd_table(t_ms *ms)
{
	free_matrix(ms->cmds.command);
	ms->cmds.command = malloc(100 * sizeof(char *));
	ms->cmds.command[0] = NULL;
}
