/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:46:53 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/04 23:34:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_var_from_env(t_ms *ms, int i);

void	unset(t_ms *ms, char *var)
{
	int	i;

	var = ft_strjoin(var, "=");
	i = 0;
	while (ms->init.envp[i])
	{
		if (!ft_strncmp(var, ms->init.envp[i], ft_strlen(var)))
		{
			remove_var_from_env(ms, i);
			break ;
		}
		i++;
	}
	free(var);
}

static void	remove_var_from_env(t_ms *ms, int i)
{
	while (ms->init.envp[i])
	{
		ms->init.envp[i] = ms->init.envp[i + 1];
		i++;
	}
}
