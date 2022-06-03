/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirect_from_start_of_str.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:11:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:20:40 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_redirect_from_start_of_str(t_ms *ms)
{
	int		i;
	int		mtx_len;
	char	**mtx_aux;

	mtx_len = ft_mtxlen(ms->cmds.command);
	ms->parser.last_redirect = -1;
	i = 0;
	if (ms->cmds.command[i][0] != '<' && ms->cmds.command[i][0] != '>')
		return ;
	i = get_last_redirect_position(ms, i);
	if (ms->parser.last_redirect < i)
	{
		mtx_len = mtx_len - (ms->parser.last_redirect + 1);
		mtx_aux = malloc((mtx_len + 1) * sizeof(char *));
		copy_mtx(mtx_aux, ms->cmds.command, ms->parser.last_redirect + 1, \
			mtx_len);
		ms->cmds.command = malloc((mtx_len + 1) * sizeof(char *));
		copy_mtx(ms->cmds.command, mtx_aux, 0, mtx_len);
	}
}
