/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 06:05:43 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/26 06:06:02 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	reset_std_fds(t_ms *ms)
{
	dup42(ms->cmds.stin, STDIN_FILENO);
	dup42(ms->cmds.stout, STDOUT_FILENO);
}
