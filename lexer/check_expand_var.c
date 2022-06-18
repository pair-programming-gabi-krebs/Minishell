/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:27:19 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/18 10:53:11 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	expand_var(t_ms *ms, char **echo, int i);
static char	*search_var_on_env(t_ms *ms, char *str);
static void	handle_exit_code_variable_expansion(t_ms *ms);
static void	handle_exit_code(t_ms *ms, int i);

void	check_expand_var(t_ms *ms)
{
	char	**token;
	int		i;

	i = 0;
	handle_exit_code_variable_expansion(ms);
	while (ms->lexer.tokens[i])
	{
		token = ft_split(ms->lexer.tokens[i], ' ');
		if (!strict_strcmp(ms->lexer.tokens[i], "$"))
		{
			i++;
			free_matrix(token);
			continue ;
		}
		else if (ms->lexer.tokens[i][0] == '$' && \
			(ms->lexer.flag_quote[i] == '\"' || ms->lexer.flag_quote[i] == '.'))
			expand_var(ms, ms->lexer.tokens, i);
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
	else
	{
		free(echo[i]);
		echo[i] = ft_strdup("");
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

static void	handle_exit_code_variable_expansion(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.i_token)
	{
		if (!strict_strcmp("$?", ms->lexer.tokens[i])
			&& ms->lexer.flag_quote[i] != '\'')
			handle_exit_code(ms, i);
		i++;
	}
}

static void	handle_exit_code(t_ms *ms, int i)
{
	char	*aux;

	free(ms->lexer.tokens[i]);
	aux = ft_itoa(ms->cmds.exit_status);
	ms->lexer.tokens[i] = ft_strdup(aux);
	free(aux);
}
