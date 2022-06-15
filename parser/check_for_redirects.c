/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:44 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/14 21:21:57 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	redirect_validations(t_ms *ms, int inf_counter, int out_counter);
static int	has_redirect(t_ms *ms, char *str1, char *str2, int i);
static void	init(t_ms *ms);

int	check_for_redirects(t_ms *ms)
{
	int	i;

	i = -1;
	init(ms);
	while (ms->cmds.command[++i])
	{
		if (has_redirect(ms, ms->cmds.command[i], "<<", i))
		{
			ms->cmds.limiter = ft_strdup(ms->cmds.command[i + 1]);
			get_name_set_count_in(ms, ms->cmds.inf, i, ms->cmds.inf_counter);
			//here_doc(ms);
			ms->cmds.hdoc_counter = 1;
		}
		else if (has_redirect(ms, ms->cmds.command[i], ">>", i))
		{
			get_name_set_count_out(ms, ms->cmds.out, i, ms->cmds.out_counter);
			ms->cmds.append_flag = 1;
		}
		else if (has_redirect(ms, ms->cmds.command[i], "<", i))
			get_name_set_count_in(ms, ms->cmds.inf, i, ms->cmds.inf_counter);
		else if (has_redirect(ms, ms->cmds.command[i], ">", i))
			get_name_set_count_out(ms, ms->cmds.out, i, ms->cmds.out_counter);
	}
	if (redirect_validations(ms, ms->cmds.inf_counter, ms->cmds.out_counter))
		return (1);
	return (0);
}

static void	init(t_ms *ms)
{
	ms->cmds.out_counter = 0;
	ms->cmds.inf_counter = 0;
	ms->cmds.hdoc_counter = 0;
	ms->cmds.append_flag = 0;
	free(ms->cmds.limiter);
}

static int	has_redirect(t_ms *ms, char *str1, char *str2, int i)
{
	if (!strict_strcmp(str1, str2) && ms->cmds.command[i + 1])
		return (1);
	return (0);
}

static int	redirect_validations(t_ms *ms, int inf_counter, int out_counter)
{
	if (inf_counter == 0)
	{
		free_matrix(ms->cmds.inf);
		ms->cmds.inf = malloc(2048 * sizeof(char **));
		ms->cmds.inf[0] = NULL;
		ms->cmds.inf_fd = -1;
	}
	if (out_counter == 0)
	{
		free_matrix(ms->cmds.out);
		ms->cmds.out = malloc(2048 * sizeof(char **));
		ms->cmds.out[0] = NULL;
		ms->cmds.out_fd = -1;
	}
	if (ms->cmds.inf_counter > 0 || ms->cmds.out_counter > 0
		|| ms->cmds.hdoc_counter > 0)
		return (1);
	return (0);
}
