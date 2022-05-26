/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:46:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/25 20:39:05 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	export(t_ms *ms, char *var)
{
	t_list	*node;

	if (var)
	{
		node = ft_lstnew(ft_strdup(var));
		ft_lstadd_back(ms->list, node);
	}
}
