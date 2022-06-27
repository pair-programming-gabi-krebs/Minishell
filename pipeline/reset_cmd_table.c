/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:50:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/27 02:45:22 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	reset_cmd_table(t_ms *ms)
{
	free_matrix(ms->cmds.command);
	ms->cmds.command = malloc(100 * sizeof(char *));
	ms->cmds.command[0] = NULL;
	free(ms->cmds.flag_quote);
	ms->cmds.flag_quote = NULL;
	unlink("hdoc_file");
}
