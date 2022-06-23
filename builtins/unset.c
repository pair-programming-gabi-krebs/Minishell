/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:46:53 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/23 17:00:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	remove_var_from_env(t_list *node, t_ms *ms);
static int	check_var_spell(char *var);
static void	handle_invalid_identifier(t_ms *ms, int i);

void	unset(t_ms *ms)
{
	t_list	*node;
	int		i;
	char	*var;

	node = *(ms->list);
	i = 0;
	while (ms->cmds.command[++i])
	{
		if (!check_var_spell(ms->cmds.command[i]))
			handle_invalid_identifier(ms, i);
		else
		{
			var = ft_strjoin(ms->cmds.command[i], "=");
			while (node->next != NULL
				&& ft_strncmp(var, node->content, ft_strlen(var)) != 0)
				node = node->next;
			if (!ft_strncmp(var, node->content, ft_strlen(var)))
				remove_var_from_env(node, ms);
			free(var);
		}
	}
	ms->cmds.exit_status = 0;
}

static void	handle_invalid_identifier(t_ms *ms, int i)
{
	ft_putstr_fd("unset: `", 2);
	ft_putstr_fd(ms->cmds.command[i], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
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

static int	check_var_spell(char *var)
{
	char	*var_cpy;

	var_cpy = ft_strdup(var);
	if ((ft_isalpha(var[0]) || var[0] == '_') && ft_isalnum_underscore(var_cpy))
	{
		free(var_cpy);
		return (1);
	}
	free(var_cpy);
	return (0);
}
