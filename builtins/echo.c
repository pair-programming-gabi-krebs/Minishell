/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/25 23:33:01 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*search_var_on_env(t_ms *ms, char *str);
static void	expand_var(t_ms *ms, char **echo, int j);
static char	*join_strings(char **echo);

void	echo(t_ms *ms)
{
	int		has_nl;
	int		i;
	int		j;
	char	**echo;
	char	*str;


	has_nl = 1;
	if (!ft_strncmp(ms->cmds.command[1], "-n", ft_strlen(ms->cmds.command[1])))
		has_nl = 0;
	i = 1;
	// for(int j = 0; j < ms->lexer.i_token; j++)
	// 	printf("Token[%d]: %s\n", j, ms->lexer.tokens[j]);
	while (ms->cmds.command[i])
	{
		printf("comands: %s\n", ms->cmds.command[i]);
		if (has_nl)
		{
			echo = ft_split(ms->cmds.command[i], ' ');
			j = 0;
			while (echo[j])
			{
				if (echo[j][0] == '$' && (ms->lexer.flag_quote == '\"'
					|| !ms->lexer.flag_quote))
					expand_var(ms, echo, j);
				j++;
			}
			str = join_strings(echo);
			printf("%s\n", str);
			free(str);
			free_matrix(echo);
		}
		else if (ms->cmds.command[i + 1])
		{

			//printf("%s", ms->cmds.command[i + 1]);
		}
		i++;
	}
}

static void	expand_var(t_ms *ms, char **echo, int j)
{
	char	*str;

	str = ft_strdup(echo[j]);
	free(echo[j]);
	echo[j] = search_var_on_env(ms, (str + 1));
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
		if (node->next == NULL && !ft_strncmp(node->content, str, ft_strlen(str)))
		{
			var = ft_strchr(node->content, '=');
			return (ft_strdup(var + 1));
		}
	}
	return (NULL);
}

static char	*join_strings(char **echo)
{
	char	*aux;
	char	*str;
	int		i;

	i = 0;
	while (echo[i])
	{
		str = ft_strdup(echo[i]);
		free(echo[i]);
		aux = ft_strjoin(str, " ");
		echo[i] = ft_strdup(aux);
		free(aux);
		free(str);
		i++;
	}
	i = 0;
	str = ft_strdup("");
	while (echo[i])
	{
		aux = ft_strjoin(str, echo[i]);
		free(str);
		str = ft_strdup(aux);
		free(aux);
		i++;
	}
	return (str);
}

// Ver se tem um $ na string e se sim, se ele está entre aspas simples

// echo "teste do $HOME oi $PWD testinho"
// [0] teste
// [1] do
// [2] $HOME
// [3] oi
// [4] $PWD
// [5] testinho

