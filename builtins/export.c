/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:46:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/04 23:59:27 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export(t_ms *ms, char *var)
{
	int	i;

	i = ft_mtxlen(ms->init.envp);
	ms->init.envp[i] = ft_strdup(var);
	ms->init.envp[i + 1] = NULL;
}
