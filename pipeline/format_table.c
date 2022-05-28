/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/27 23:04:23 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_redirect_name(t_ms *ms, char *redirect, int start);

void	format_table(t_ms *ms, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		if (!ft_strncmp(ms->lexer.tokens[start], "<<", \
			ft_strlen(ms->lexer.tokens[start])))
			printf("<<\n");
		else if (!ft_strncmp(ms->lexer.tokens[start], ">>", \
			ft_strlen(ms->lexer.tokens[start])))
			printf(">>\n");
		else if (ms->lexer.tokens[start][0] == '>')
			get_redirect_name(ms, ms->cmds.out, start);
		else if (ms->lexer.tokens[start][0] == '<')
			get_redirect_name(ms, ms->cmds.inf, start);
		else
		{
			ms->cmds.command[j] = ft_strdup(ms->lexer.tokens[start]);
			ms->cmds.command[j + 1] = NULL;
			j++;
		}
		start++;
	}
}

static void	get_redirect_name(t_ms *ms, char *redirect, int start)
{
	if (redirect)
		free(redirect);
	if (ms->lexer.tokens[start + 1])
		redirect = ft_strdup(ms->lexer.tokens[start + 1]);
	printf("redirect: %s\n", redirect);
}
