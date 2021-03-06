/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:12:59 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/20 22:44:02 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	build_cmd_table(t_ms *ms)
{
	int	i;
	int	has_format;

	has_format = 0;
	i = ms->cmds.cmd_index;
	while (i < ms->lexer.i_token)
	{
		if (ms->lexer.tokens[i][0] == '|'
			&& ft_strlen(ms->lexer.tokens[i]) == 1)
		{
			format_table(ms, ms->cmds.cmd_index, i);
			has_format = 1;
			i++;
			break ;
		}
		i++;
	}
	if (!has_format)
		format_table(ms, ms->cmds.cmd_index, i);
	ms->cmds.cmd_index = i;
}
