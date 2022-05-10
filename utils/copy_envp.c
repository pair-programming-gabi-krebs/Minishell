/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:58:21 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/09 22:12:30 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_envp(t_ms *ms)
{
	int		i;
	int		mtx_len;
	t_list	*node;

	ms->list = malloc(1 * sizeof(t_list*));
	*(ms->list) = NULL;
	mtx_len = ft_mtxlen(ms->init.envp);
	i = 0;
	while (i < mtx_len)
	{
		node = ft_lstnew(ft_strdup(ms->init.envp[i]));
		ft_lstadd_back(ms->list, node);
		i++;
	}
}
