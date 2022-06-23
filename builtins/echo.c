/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/23 16:55:18 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*join_strings(char **echo);
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
	ms->cmds.exit_status = 0;
}

static void	print_echo(t_ms *ms, int i)
{
	char	**echo;
	char	*str;
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
		echo = ft_split(ms->cmds.command[i], ' ');
		str = join_strings(echo);
		printf("%s", str);
		free(str);
		free_matrix(echo);
		i++;
	}
}

static char	*join_strings(char **echo)
{
	char	*aux;
	char	*str;
	int		i;

	i = -1;
	while (echo[++i])
	{
		str = ft_strdup(echo[i]);
		free(echo[i]);
		aux = ft_strjoin(str, " ");
		echo[i] = ft_strdup(aux);
		free(aux);
		free(str);
	}
	i = -1;
	str = ft_strdup("");
	while (echo[++i])
	{
		aux = ft_strjoin(str, echo[i]);
		free(str);
		str = ft_strdup(aux);
		free(aux);
	}
	return (str);
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
