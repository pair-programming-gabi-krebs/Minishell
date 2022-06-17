/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:06:45 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/17 19:44:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_env(t_ms *ms, char *var);

void	parse_env(t_ms *ms)
{
	char	*get_env_path;

	get_env_path = get_env(ms, "PATH=");
	if (get_env_path)
	{
		ms->cmds.path = ft_strchr(get_env_path, '/');
		if (ms->cmds.path)
			ms->cmds.bin = ft_split(ms->cmds.path, ':');
	}
}

static char	*get_env(t_ms *ms, char *var)
{
	t_list	*node;

	node = *(ms->list);
	while (node->next != NULL)
	{
		if (!ft_strncmp(node->content, var, 5))
			return (node->content);
		node = node->next;
		if (node->next == NULL && !ft_strncmp(node->content, var, 5))
			return (node->content);
	}
	return (NULL);
}
