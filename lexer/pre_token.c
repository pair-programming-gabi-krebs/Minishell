/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 21:52:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	pre_tokenization(t_ms *ms, int i);
static void	line_formater(t_ms *ms);
static int	strjoin_quotes(t_ms *ms, int i);
static void	join_strings(t_ms *ms, int i);
static void	strjoin_add_space(t_ms *ms, int i);

void	pre_token(t_ms *ms)
{
	int	i;

	ms->tk.j = 0;
	ms->tk.k = 0;
	ms->tk.len = 0;
	ms->tk.mtx = malloc(100 * sizeof(char **));
	ms->tk.line = NULL;
	i = 0;
	while (ms->prompt.line[i])
	{
		while (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]))
		{
			i++;
			if (!ms->prompt.line[i])
				break ;
		}
		pre_tokenization(ms, i);
		while (ms->prompt.line[i] && is_special(ms, ms->prompt.line[i]))
		{
			i++;
			if (!ms->prompt.line[i])
				break ;
		}
		pre_tokenization(ms, i);
	}
	ms->tk.mtx[ms->tk.j] = '\0';
	line_formater(ms);
	free_matrix(ms->tk.mtx);
}

static void	pre_tokenization(t_ms *ms, int i)
{
	char	*str;
	char	*strdup;

	strdup = ft_strdup(ms->prompt.line);
	strdup[i] = '\0';
	str = ft_substr(strdup, ms->tk.k, ft_strlen(strdup));
	ms->tk.mtx[ms->tk.j] = ft_strdup(str);
	ms->tk.j++;
	ms->tk.k = i;
	free(str);
	free(strdup);
}

static void	line_formater(t_ms *ms)
{
	int		mtx_len;
	int		i;

	mtx_len = ft_mtxlen(ms->tk.mtx);
	i = 0;
	while (i < mtx_len)
	{
		if (ms->tk.mtx[i][0] != DOUBLE_QUOTE
			&& ms->tk.mtx[i][0] != SINGLE_QUOTE)
			strjoin_add_space(ms, i);
		else
		{
			i = strjoin_quotes(ms, i);
			continue ;
		}
		i++;
	}
}

static void	strjoin_add_space(t_ms *ms, int i)
{
	char	*line;
	char	*aux1;
	char	*aux2;
	char	*str;

	str = " ";
	if (ms->tk.mtx[i + 1] && (ms->tk.mtx[i + 1][0] == DOUBLE_QUOTE
		|| ms->tk.mtx[i + 1][0] == SINGLE_QUOTE))
		str = "";
	aux1 = ft_strdup(ms->tk.mtx[i]);
	line = ft_strjoin(aux1, str);
	if (ms->tk.line)
		aux2 = ft_strdup(ms->tk.line);
	else
		aux2 = ft_strdup("");
	free(ms->tk.line);
	ms->tk.line = ft_strjoin(aux2, line);
	free(aux2);
	free(line);
	free(aux1);
}

static int	strjoin_quotes(t_ms *ms, int i)
{
	char	chr;

	chr = ms->tk.mtx[i][0];
	if (!ms->tk.line)
		ms->tk.line = ft_strdup(ms->tk.mtx[i]);
	else
		join_strings(ms, i);
	i++;
	while (ms->tk.mtx[i] && ms->tk.mtx[i][0] != chr)
	{
		join_strings(ms, i);
		i++;
	}
	return (i);
}

static void	join_strings(t_ms *ms, int i)
{
	char	*aux;

	aux = ft_strdup(ms->tk.line);
	free(ms->tk.line);
	ms->tk.line = ft_strjoin(aux, ms->tk.mtx[i]);
	free(aux);
}
