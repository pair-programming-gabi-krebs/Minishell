/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:16:27 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 19:19:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	dup_infile(t_ms *ms, int stin, int i)
{
	if (stin == -1 || (i == 0 && stin == -1))
		stin = dup(STDIN_FILENO);
	if (i == 0 && stin == -1)
	{
		stin = dup(STDIN_FILENO);
		return (stin);
	}
	dup42(ms->cmds.inf_fd, STDIN_FILENO);
	return (stin);
}
