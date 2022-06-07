/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:27:19 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/06 22:27:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	expand_var(t_ms *ms, char **echo, int i);
static char	*search_var_on_env(t_ms *ms, char *str);

void	check_expand_var(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->lexer.tokens[i])
	{
		char **token = ft_split(ms->lexer.tokens[i], ' ');
		printf("ms->lexer.tokens[i]: %s\n", ms->lexer.tokens[i]);
		if (ms->lexer.tokens[i][0] == '$' && (ms->lexer.flag_quote == '\"'
			|| !ms->lexer.flag_quote))
		{
			expand_var(ms, ms->lexer.tokens, i);
			printf("ms->lexer.tokens[i]: %s\n", ms->lexer.tokens[i]);
		}
		i++;
		free_matrix(token);
	}
}

static void	expand_var(t_ms *ms, char **echo, int i)
{
	char	*str;
	char	*aux;

	str = ft_strdup(echo[i]);
	aux = search_var_on_env(ms, (str + 1));
	if (aux)
	{
		free(echo[i]);
		echo[i] = search_var_on_env(ms, (str + 1));
	}
	free(aux);
	free(str);
}

static char	*search_var_on_env(t_ms *ms, char *str)
{
	t_list	*node;
	char	*var;

	node = *(ms->list);
	while (node->next != NULL)
	{
		if (!ft_strncmp(node->content, str, ft_strlen(str)))
		{
			var = ft_strchr(node->content, '=');
			var = ft_strdup(var + 1);
			return (var);
		}
		node = node->next;
		if (node->next == NULL && !ft_strncmp(node->content, \
			str, ft_strlen(str)))
		{
			var = ft_strchr(node->content, '=');
			return (ft_strdup(var + 1));
		}
	}
	return (NULL);
}