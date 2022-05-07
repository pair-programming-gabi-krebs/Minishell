/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:43:45 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/06 23:57:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env(t_ms *ms)
{
	t_list	*node;

	node = *(ms->list);
	while (node->next != NULL)
	{
		printf("%s\n", (char *)node->content);
		node = node->next;
	}
	printf("%s\n", (char *)node->content);
}
