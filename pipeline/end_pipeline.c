/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:32:52 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/17 22:33:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	end_pipeline(t_ms *ms)
{
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	close(ms->cmds.fd[0]);
	close(ms->cmds.fd[1]);
}
