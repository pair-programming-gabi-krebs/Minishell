/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:19:11 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/22 01:43:42 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_exit_arguments(t_ms *ms);
static int	check_for_non_numeric_values(t_ms *ms);
static int	check_for_non_numeric_values_first_arg(t_ms *ms);
static void	exit_with_num_arg(t_ms *ms);

void	handle_exit(t_ms *ms)
{
	int		exit_args;

	exit_args = count_exit_arguments(ms);
	if (!check_for_non_numeric_values_first_arg(ms))
	{
		write(1, "exit\n", 6);
		printf("exit: %s: numeric argument required", ms->cmds.command[1]);
		exit_with_num_arg(ms);
	}
	if (exit_args > 2)
		write(2, "exit\nexit: too many arguments\n", 30);
	else
	{
		if (!check_for_non_numeric_values(ms))
			printf("exit: %s: numeric argument required\n", \
				ms->cmds.command[1]);
		else
			exit_with_num_arg(ms);
	}
}

static	void	exit_with_num_arg(t_ms *ms)
{
	int	numeric_return;

	numeric_return = ft_atoi(ms->cmds.command[1]);
	ft_exit(ms, numeric_return);
}

static int	check_for_non_numeric_values_first_arg(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[1][i])
	{
		if (!ft_isdigit(ms->cmds.command[1][i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_for_non_numeric_values(t_ms *ms)
{
	int	i;
	int	j;

	i = 1;
	while (ms->cmds.command[i])
	{
		j = 0;
		while (ms->cmds.command[i][j])
		{
			if (!ft_isdigit(ms->cmds.command[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	count_exit_arguments(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->cmds.command[i])
		i++;
	return (i);
}
