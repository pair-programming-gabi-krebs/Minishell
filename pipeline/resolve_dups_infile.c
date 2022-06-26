/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_infile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:24:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/26 05:53:25 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	resolve_dups_infile(t_ms *ms, int i)
{
	if (ms->cmds.inf_fd != -1)
		dup42(ms->cmds.inf_fd, STDIN_FILENO);
	else if (i >= 0 && ms->cmds.aux_fd != -1)
		dup42(ms->cmds.aux_fd, STDIN_FILENO);
	else if (i >= 0 && ms->cmds.aux_fd == -1)
		dup42(ms->cmds.fd[0], STDIN_FILENO);
}
