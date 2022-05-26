/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:46:53 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/25 20:40:35 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_var_from_env(t_list *node, t_ms *ms);

void	unset(t_ms *ms, char *var)
{
	t_list *node;

	if (var)
	{
		node = *(ms->list);
		var = ft_strjoin(var, "=");
		while (node->next != NULL
			&& ft_strncmp(var, node->content, ft_strlen(var)) != 0)
			node = node->next;
		if (!ft_strncmp(var, node->content, ft_strlen(var)))
			remove_var_from_env(node, ms);
		free(var);
	}
}

static void	remove_var_from_env(t_list *node, t_ms *ms)
{
	t_list	*ptr;
	t_list	*ptr2;

	if (node->next == NULL)
	{
		ptr = node->prv;
		ptr->next = NULL;
	}
	else if (node->prv == NULL)
	{
		*(ms->list) = node->next;
		ptr = *(ms->list);
		ptr->prv = NULL;
	}
	else
	{
		ptr = node->prv;
		ptr2 = node->next;
		ptr->next = ptr2;
		ptr2->prv = ptr;
	}
	ft_lstdelone(node, free);
}
