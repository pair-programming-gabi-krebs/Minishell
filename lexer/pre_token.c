/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/28 22:16:11 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	pre_tokenization(t_ms *ms, int i);
static void	line_formater(t_ms *ms);
static int	strjoin_quotes(t_ms *ms, int i);
static void	join_strings(t_ms *ms, int i);
static void	strjoin_add_space(t_ms *ms, int i);

void	pre_token(t_ms *ms)
{
	int	i;

	i = 0;
	ms->tk.j = 0;
	ms->tk.k = 0;
	ms->tk.len = 0;
	ms->tk.mtx = malloc(100 * sizeof(char **)); // mudar esse 10
	while ((size_t)i < ft_strlen(ms->prompt.line))
	{
		while (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]))
			i++;
		i = pre_tokenization(ms, i);
		while (ms->prompt.line[i] && is_special(ms, ms->prompt.line[i])
			&& ms->prompt.line[i] == ms->prompt.line[i + 1])
		{
			i++;
		}
		i = pre_tokenization(ms, i);
	}
	printf("j: %d\n", ms->tk.j);
	ms->tk.mtx[ms->tk.j] = '\0';
	line_formater(ms);
	free_matrix(ms->tk.mtx);
	printf("ms->tk.line = %s\n", ms->tk.line);
}

static int	pre_tokenization(t_ms *ms, int i)
{
	char	*str;
	char	*strdup;

	strdup = ft_strdup(ms->prompt.line);
	strdup[i] = '\0';

	str = ft_substr(strdup, ms->tk.k, ft_strlen(strdup));
	ms->tk.mtx[ms->tk.j] = ft_strdup(str);
	printf("ms->tk.mtx[%d]:%s\n\n", ms->tk.j, ms->tk.mtx[ms->tk.j]);

	ms->tk.j++;
	ms->tk.k = i;

	free(str);
	free(strdup);
	i++;
	return (i);
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
	join_strings(ms, i);
	i++;
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
