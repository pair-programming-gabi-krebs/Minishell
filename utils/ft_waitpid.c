/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:37:09 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/16 20:42:51 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_waitpid(t_ms *ms, int pid)
{
	waitpid(pid, &ms->cmds.exit_status, 0);
	if (WIFEXITED(ms->cmds.exit_status))
		ms->cmds.exit_status = WEXITSTATUS(ms->cmds.exit_status);
	else if (WIFSIGNALED(ms->cmds.exit_status))
		ms->cmds.exit_status = WTERMSIG(ms->cmds.exit_status) + 128;
}
