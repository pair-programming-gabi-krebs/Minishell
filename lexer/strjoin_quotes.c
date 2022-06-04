/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:05:45 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 22:14:24 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	join_strings(t_ms *ms, int i);

int	strjoin_quotes(t_ms *ms, int i)
{
	char	chr;

	chr = ms->tk.mtx[i][0];
	if (!ms->tk.line)
		ms->tk.line = ft_strdup(ms->tk.mtx[i]);
	else
		join_strings(ms, i);
	i++;
	while (ms->tk.mtx[i] && ms->tk.mtx[i][0] != chr)
	{
		join_strings(ms, i);
		i++;
	}
	return (i);
}

static void	join_strings(t_ms *ms, int i)
{
	char	*aux;

	aux = ft_strdup(ms->tk.line);
	free(ms->tk.line);
	ms->tk.line = ft_strjoin(aux, ms->tk.mtx[i]);
	free(aux);
}
