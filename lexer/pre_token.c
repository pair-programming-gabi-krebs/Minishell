/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/27 21:15:45 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	pre_tokenization(t_ms *ms, int i);
static void	line_formater(t_ms *ms);
static int	strjoin_quotes(t_ms *ms, int i);
static void	join_strings(t_ms *ms, int i);

void	pre_token(t_ms *ms)
{
	int		i;

	i = 0;
	ms->tk.j = 0;
	ms->tk.k = 0;
	ms->tk.len = 0;
	ms->tk.mtx = malloc(10 * sizeof(char **)); // mudar esse 10
	while (ms->prompt.line[i])
	{
		while (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]))
			i++;
		i = pre_tokenization(ms, i);
		while (ms->prompt.line[i] && is_special(ms, ms->prompt.line[i]))
			i++;
		i = pre_tokenization(ms, i);
	}
	ms->tk.mtx[i] = '\0';
	line_formater(ms);
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
	return (i);
}

static void	line_formater(t_ms *ms)
{
	char	*line1;
	char	*line2;
	char	*aux1;
	char	*aux2;
	int		mtx_len;
	int		i;

	line1 = NULL;
	line2 = NULL;
	mtx_len = ft_mtxlen(ms->tk.mtx);
	i = 0;
	while (i < mtx_len)
	{
		if (ms->tk.mtx[i][0] != DOUBLE_QUOTE
			&& ms->tk.mtx[i][0] != SINGLE_QUOTE)
		{
			aux1 = ft_strdup(ms->tk.mtx[i]);
			line1 = ft_strjoin(aux1, " ");
			if (line2)
				aux2 = ft_strdup(line2);
			else
				aux2 = ft_strdup("");
			free(line2);
			line2 = ft_strjoin(aux2, line1);
			free(aux2);
			free(line1);
			free(aux1);
		}
		else
		{
			i = strjoin_quotes(ms, i);
			continue ;
		}
		i++;
	}

}

static int	strjoin_quotes(t_ms *ms, int i)
{
	char	chr;

	chr = ms->tk.mtx[i][0];
	ms->tk.line = ft_strdup(ms->tk.mtx[i]);
	i++;
	while (ms->tk.mtx[i][0] != chr)
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
