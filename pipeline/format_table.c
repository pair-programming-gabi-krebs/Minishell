/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/17 22:13:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	format_table(t_ms *ms, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		if (ms->lexer.tokens[start][0] == '>')
		{
			if (ms->cmds.out)
				free(ms->cmds.out);
			ms->cmds.out = ft_strdup(ms->lexer.tokens[start + 1]);
		}
		else if (ms->lexer.tokens[start][0] == '<')
		{
			if (ms->cmds.inf)
				free(ms->cmds.inf);
			ms->cmds.inf = ft_strdup(ms->lexer.tokens[start + 1]);
		}
		else
		{
			ms->cmds.command[j] = ft_strdup(ms->lexer.tokens[start]);
			ms->cmds.command[j + 1] = NULL;
			j++;
		}
		start++;
	}
}
