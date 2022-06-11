/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:46:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/11 00:52:22 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	update_var(t_list *node, char *var_name, char *var);
static int	already_has_var(t_ms *ms, char *var);
static char	*get_var_name(char *content);

void	export(t_ms *ms, char *var)
{
	t_list	*node;

	if (var)
	{
		if (already_has_var(ms, var))
			return ;
		node = ft_lstnew(ft_strdup(var));
		ft_lstadd_back(ms->list, node);
	}
}

static int	already_has_var(t_ms *ms, char *var)
{
	t_list	*node;
	char	*var_name;

	node = *(ms->list);
	while (node->next != NULL)
	{
		var_name = get_var_name(node->content);
		if (!ft_strncmp(var, var_name, ft_strlen(var_name)))
		{
			update_var(node, var_name, var);
			return (1);
		}
		free(var_name);
		var_name = NULL;
		node = node->next;
	}
	var_name = get_var_name(node->content);
	if (!ft_strncmp(var, var_name, ft_strlen(var_name)))
	{
		update_var(node, var_name, var);
		return (1);
	}
	free(var_name);
	return (0);
}

static void	update_var(t_list *node, char *var_name, char *var)
{
	free(node->content);
	node->content = ft_strdup(var);
	free(var_name);
}

static char	*get_var_name(char *content)
{
	int		equals_index;

	equals_index = strichar(content, 0, '=');
	return (ft_substr(content, 0, equals_index + 1));
}
