/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:13:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/02 23:50:46 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter);
static int	check_for_redirects(t_ms *ms);
static void	remove_redirect_from_end_of_str(t_ms *ms);
static void	remove_redirect_from_start_of_str(t_ms *ms);
static int	get_last_redirect_position(t_ms *ms, int i);

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

static int	check_for_redirects(t_ms *ms)
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
	if (inf_counter == 0)
	{
		free_matrix(ms->cmds.inf);
		ms->cmds.inf = malloc(2048 * sizeof(char **));
		ms->cmds.inf[0] = NULL;
		ms->cmds.out_fd = -1;
	}
	if (out_counter == 0)
	{
		free_matrix(ms->cmds.out);
		ms->cmds.out = malloc(2048 * sizeof(char **));
		ms->cmds.out[0] = NULL;
		ms->cmds.out_fd = -1;
	}
	if (inf_counter > 0 || out_counter > 0)
		return (1);
	return (0);
}

static void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter)
{
	if (ms->cmds.command[i + 1])
	{
		if (redirect[counter])
			free(redirect[counter]);
		redirect[counter] = ft_strdup(ms->cmds.command[i + 1]);
	}
	redirect[counter + 1] = NULL;
}

static void	remove_redirect_from_start_of_str(t_ms *ms)
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

static int	get_last_redirect_position(t_ms *ms, int i)
{
	int	stop_count;

	stop_count = 0;
	while (ms->cmds.command[i] && stop_count < 2)
	{
		if (ms->cmds.command[i][0] == '<' && ms->cmds.command[i + 1])
		{
			ms->parser.last_redirect = ms->parser.last_redirect + 2;
			stop_count = 0;
		}
		else if (ms->cmds.command[i][0] == '>' && ms->cmds.command[i + 1])
		{
			ms->parser.last_redirect = ms->parser.last_redirect + 2;
			stop_count = 0;
		}
		else
			stop_count++;
		i++;
	}
	return (i);
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
}
