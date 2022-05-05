/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:45 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/05 14:39:35 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->prompt.cpy_envp[i])
	{
		printf("%s\n", ms->prompt.cpy_envp[i]);
		i++;
	}
}
