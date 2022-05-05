/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:46:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/05 16:37:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export(t_ms *ms, char *var)
{
	int	i;

	i = ft_mtxlen(ms->prompt.cpy_envp);
	ms->prompt.cpy_envp[i] = ft_strdup(var);
	ms->prompt.cpy_envp[i + 1] = NULL;
}
