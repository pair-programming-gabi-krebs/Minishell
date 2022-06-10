/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:32:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/09 23:11:58 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	end_pipeline(t_ms *ms)
{
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	if (ms->cmds.fd[0] != -1)
		close(ms->cmds.fd[0]);
	if (ms->cmds.fd[1] != -1)
		close(ms->cmds.fd[1]);
	ms->cmds.cmd_index = 0;
	ms->parser.pipes_qtn = 0;
}
