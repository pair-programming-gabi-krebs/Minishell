/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:45 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/05 23:41:18 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(t_ms *ms)
{
	while (ms->node->prv != NULL)
		ms->node = ms->node->prv;
	while (ms->node->next != NULL)
	{
		printf("%s\n", (char *)ms->node->content);
		ms->node = ms->node->next;
	}
}
