/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_dups_infile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:24:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 19:35:04 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	resolve_dups_infile(t_ms *ms, int stin, int i)
{
	if (i == -1 && ms->cmds.inf_fd != -1)
		stin = dup_infile(ms, stin, i);
	else if (i >= 0 && ms->cmds.inf_fd != -1)
		stin = dup_infile(ms, stin, i);
	else if (i >= 0)
	{
		stin = dup_infile(ms, stin, i);
		if (ms->cmds.inf_fd == -1)
			dup42(ms->cmds.fd[0], STDIN_FILENO);
		else
			dup42(ms->cmds.inf_fd, STDIN_FILENO);
	}
	return (stin);
}
