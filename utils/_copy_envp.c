/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:33:55 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/05 20:31:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_envp(t_ms *ms)
{
	int	i;
	int	j;

	j = ft_mtxlen(ms->init.envp);
    ms->prompt.cpy_envp = malloc((j + 1) * sizeof(char*));
	i = 0;
	while (ms->init.envp[i])
	{
		ms->prompt.cpy_envp[i] = ft_strdup(ms->init.envp[i]);
		i++;
	}
	ms->prompt.cpy_envp[i] = NULL;
}