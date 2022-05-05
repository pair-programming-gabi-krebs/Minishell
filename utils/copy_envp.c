/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:33:55 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/05 14:46:11 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_envp(t_ms *ms)
{
	int	i;
	
	ms->prompt.cpy_envp = malloc(1000 * sizeof(char));
	i = 0;
	while (ms->init.envp[i])
	{
		ms->prompt.cpy_envp[i] = ft_strdup(ms->init.envp[i]);
		i++;
	}
	ms->prompt.cpy_envp[i] = NULL;
}