/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:32:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/27 00:54:14 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	fd_collector(void);

void	end_pipeline(t_ms *ms)
{
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	fd_collector();
	ms->cmds.cmd_index = 0;
	ms->parser.pipes_qtn = 0;
}

static void	fd_collector(void)
{
	int	fd;

	fd = 3;
	while (fd < 512)
		close(fd++);
}
