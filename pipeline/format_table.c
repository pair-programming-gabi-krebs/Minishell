/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/31 00:01:25 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter);
static void	check_for_redirects(t_ms *ms);
static void	remove_redirect_from_end_of_str(t_ms *ms);

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
	check_for_redirects(ms);
	remove_redirect_from_end_of_str(ms);
}

static void	remove_redirect_from_end_of_str(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[i])
	{
		if (ms->cmds.command[i][0] == '<' && ms->cmds.command[i + 1])
		{
			free(ms->cmds.command[i]);
			free(ms->cmds.command[i + 1]);
			ms->cmds.command[i] = NULL;
			ms->cmds.command[i + 1] = NULL;
		}
		else if (ms->cmds.command[i][0] == '>' && ms->cmds.command[i + 1])
		{
			free(ms->cmds.command[i]);
			free(ms->cmds.command[i + 1]);
			ms->cmds.command[i] = NULL;
			ms->cmds.command[i + 1] = NULL;
		}
		i++;
	}
	for (int q = 0; ms->cmds.command[q]; q++)
		printf(" ms->cmds.command[%d]: %s\n", q, ms->cmds.command[q]);
	
}

static void	check_for_redirects(t_ms *ms)
{
	int	i;
	int	out_counter;
	int	inf_counter;

	out_counter = 0;
	inf_counter = 0;
	i = 0;
	while (ms->cmds.command[i])
	{
		if (ms->cmds.command[i][0] == '<')
		{
			get_redirect_name(ms, ms->cmds.inf, i, inf_counter);
			inf_counter++;
		}
		else if (ms->cmds.command[i][0] == '>')
		{
			get_redirect_name(ms, ms->cmds.out, i, out_counter);
			out_counter++;
		}
		i++;
	}
/* 	for (int q = 0; ms->cmds.inf[q]; q++)
		printf("ms->cmds.inf[%d]: %s\n", q, ms->cmds.inf[q]);
	for (int k = 0; ms->cmds.out[k]; k++)
		printf("ms->cmds.out[%d]: %s\n", k, ms->cmds.out[k]); */
}

static void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter)
{
	if (ms->cmds.command[i + 1])
		redirect[counter] = ft_strdup(ms->cmds.command[i + 1]);
	redirect[counter + 1] = NULL;
}
