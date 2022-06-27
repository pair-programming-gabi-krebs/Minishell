/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/27 02:42:53 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	build_flag_array(t_ms *ms, int start, int i);

void	format_table(t_ms *ms, int start, int end)
{
	int	i;

	ms->cmds.flag_quote = malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		build_flag_array(ms, start, i);
		ms->cmds.command[i] = ft_strdup(ms->lexer.tokens[start]);
		ms->cmds.command[i + 1] = NULL;
		i++;
		start++;
	}
	ms->cmds.flag_quote[i] = '\0';
	if (check_for_redirects(ms))
	{
		remove_redirect_from_start_of_str(ms);
		remove_redirect_from_end_of_str(ms);
	}
}

static void	build_flag_array(t_ms *ms, int start, int i)
{
	if (ms->lexer.flag_quote[start] == '\'')
		ms->cmds.flag_quote[i] = '\'';
	else if (ms->lexer.flag_quote[start] == '\"')
		ms->cmds.flag_quote[i] = '\"';
	else if (ms->lexer.flag_quote[start] == '.')
		ms->cmds.flag_quote[i] = '.';
}
