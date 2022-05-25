/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:32:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/24 20:16:12 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	end_pipeline(t_ms *ms)
{
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	close(ms->cmds.fd[0]);
	close(ms->cmds.fd[1]);
	ms->cmds.cmd_index = 0;
	ms->parser.pipes_qtn = 0;
}
