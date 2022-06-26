/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:46:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/26 22:37:10 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	update_var(t_list *node, char *var_name, char *var);
static int	already_has_var(t_ms *ms, char *var);
static int	right_var_syntax(char *var);
static int	check_var_spell(char *var, int equals_index);

void	export(t_ms *ms)
{
	t_list	*node;
	int		i;

	i = 0;
	while (ms->cmds.command[++i])
	{
		if (right_var_syntax(ms->cmds.command[i]))
		{
			if (already_has_var(ms, ms->cmds.command[i]))
				continue ;
			else
			{
				node = ft_lstnew(ft_strdup(ms->cmds.command[i]));
				ft_lstadd_back(ms->list, node);
			}
		}
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

static int	right_var_syntax(char *var)
{
	int	equals_index;

	equals_index = strichar(var, 0, '=');
	if (equals_index == -1 && (ft_isalpha(var[0]) || var[0] == '_'))
		return (0);
	if (!check_var_spell(var, equals_index))
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	return (1);
}

static int	check_var_spell(char *var, int equals_index)
{
	char	*var_cpy;

	var_cpy = ft_strdup(var);
	if (equals_index > 0)
		var_cpy[equals_index] = '\0';
	if ((ft_isalpha(var[0]) || var[0] == '_') && ft_isalnum_underscore(var_cpy))
	{
		free(var_cpy);
		return (1);
	}
	free(var_cpy);
	return (0);
}
