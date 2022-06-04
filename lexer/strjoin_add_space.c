/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_add_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:08:08 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 22:08:55 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	strjoin_add_space(t_ms *ms, int i)
{
	char	*line;
	char	*aux1;
	char	*aux2;
	char	*str;

	str = " ";
	if (ms->tk.mtx[i + 1] && (ms->tk.mtx[i + 1][0] == DOUBLE_QUOTE
		|| ms->tk.mtx[i + 1][0] == SINGLE_QUOTE))
		str = "";
	aux1 = ft_strdup(ms->tk.mtx[i]);
	line = ft_strjoin(aux1, str);
	if (ms->tk.line)
		aux2 = ft_strdup(ms->tk.line);
	else
		aux2 = ft_strdup("");
	free(ms->tk.line);
	ms->tk.line = ft_strjoin(aux2, line);
	free(aux2);
	free(line);
	free(aux1);
}
