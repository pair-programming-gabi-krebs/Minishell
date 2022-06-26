/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/25 21:06:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_echo(t_ms *ms, int i);
static int	non_existent_var(t_ms *ms);

void	echo(t_ms *ms)
{
	int		has_nl;
	int		i;

	has_nl = 1;
	i = 1;
	if (!ms->cmds.command[1] || non_existent_var(ms))
	{
		printf("\n");
		return ;
	}
	if (!strict_strcmp(ms->cmds.command[1], "-n"))
	{
		has_nl = 0;
		i = 2;
	}
	print_echo(ms, i);
	if (has_nl)
		printf("\n");
	ft_putstr_fd("\b", 1);
}

static void	print_echo(t_ms *ms, int i)
{
	int		flag;

	flag = 0;
	while (ms->cmds.command[i])
	{
		if (flag == 0)
		{
			while (!strict_strcmp(ms->cmds.command[i], "-n"))
				i++;
			flag = 1;
		}
		ft_putstr_fd(ms->cmds.command[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
}

static int	non_existent_var(t_ms *ms)
{
	int	i;
	int	mtx_len;

	i = 1;
	if (ms->cmds.command[1] && !strict_strcmp(ms->cmds.command[1], "-n"))
		i = 2;
	while (ms->cmds.command[i] && ft_strlen(ms->cmds.command[i]) == 0)
		i++;
	mtx_len = ft_mtxlen(ms->cmds.command);
	if (i == mtx_len)
		return (1);
	return (0);
}
