/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_formater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:04:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/17 17:47:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	line_formater(t_ms *ms)
{
	int		mtx_len;
	int		i;

	mtx_len = ft_mtxlen(ms->tk.mtx);
	i = 0;
	while (i < mtx_len)
	{
		if (ms->tk.mtx[i][0] != DOUBLE_QUOTE
			&& ms->tk.mtx[i][0] != SINGLE_QUOTE)
			strjoin_add_space(ms, i);
		else
		{
			i = strjoin_quotes(ms, i);
			continue ;
		}
		i++;
	}
}
