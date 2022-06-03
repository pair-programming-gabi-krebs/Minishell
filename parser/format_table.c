/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:25:30 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	format_table(t_ms *ms, int start, int end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		ms->cmds.command[i] = ft_strdup(ms->lexer.tokens[start]);
		ms->cmds.command[i + 1] = NULL;
		i++;
		start++;
	}
	if (check_for_redirects(ms))
	{
		remove_redirect_from_start_of_str(ms);
		remove_redirect_from_end_of_str(ms);
	}
}
