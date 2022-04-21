/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/20 23:55:23 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_special(t_ms *ms, char c);

void	pre_token(t_ms *ms)
{
	int		j;
	int		i;
	int		k;
	int		len;
	char	character;

	i = 0;
	j = 0;
	len = 0;
	k = 0;
	ms->prompt.mtx = malloc(10 * sizeof(char **));
	while(ms->prompt.line[i])
	{
		if (is_special(ms, ms->prompt.line[i]))
		{
			ms->prompt.mtx[j] = ft_substr(ms->prompt.line, k, i-k);
			printf("ms->prompt.mtx[%d] = %s\n\n", j, ms->prompt.mtx[j]);
			j++;
			k = i;
			len = 0;
			character = ms->prompt.line[i];
			while (is_special(ms, ms->prompt.line[i]) && ms->prompt.line[i] == character)
			{
				len++;
				i++;
			}
			ms->prompt.mtx[j] = ft_substr(ms->prompt.line, k, len);
			printf("ms->prompt.mtx[%d] = %s\n\n", j, ms->prompt.mtx[j]);
			j++;
			k = i;
		}
		if (ms->prompt.line[i] && !is_special(ms, ms->prompt.line[i]) && ms->prompt.line[i + 1] == '\0')
		{
			ms->prompt.mtx[j] = ft_substr(ms->prompt.line, k, i - k + 1);
			printf("ms->prompt.mtx[%d] = %s\n\n", j, ms->prompt.mtx[j]);
		}
		if (ms->prompt.line[i])
			i++;
	}
}

int	is_special(t_ms *ms, char c)
{
	int	i;

	i = 0;
	while (ms->prompt.special[i])
	{
		if (ms->prompt.special[i] == c)
			return (1);
		i++;
	}
	return (0);
}


/*
banana<<dsadsa<oi|"hoje<<<leia"

specials = [<, >, ", ', |]
count = 0;
matrix[0] = bananaSPACE
matrix[1] = <<SPACE
matrix[2] = dsadsaSPACE
matrix[3] = <SPACE


1. conta quantos '<' tem
2. verifica se o proximo é igual a ele
3. verifica se o próximo do próximo tbm é igual

se o proximo dps do delimitador (<) == ao delimitador, aciona a flag

banana < dadsa
1- banana
2- <
3- dsadsa

achou o delimitador? Achou, verifica a flag, se for verdadeira, adiciona mais um delimitador


banana << ddasd

1- banana
2- <<
3- dsadsaasd
*/

// static void	normalize(t_ms *ms, char character, char *str);

// void	pre_token(t_ms *ms)
// {
// 	if (ft_strchr(ms->prompt.line, '|'))
// 		normalize(ms, '|', " | ");
// 	if (ft_strchr(ms->prompt.line, '<'))
// 		normalize(ms, '<', " < ");
// 	if (ft_strchr(ms->prompt.line, '>'))
// 		normalize(ms, '>', " > ");
// }

// static void	normalize(t_ms *ms, char character, char *str)
// {
// 	char	**split;
// 	char	*prev;
// 	char	*aux;
// 	int		i;

// 	split = ft_split(ms->prompt.line, character);
// 	prev = ft_strdup(split[0]);
// 	i = 1;
// 	while (i < ft_mtxlen(split))
// 	{
// 		aux = ft_strjoin(prev, str);
// 		free(prev);
// 		prev = ft_strdup(aux);
// 		free(aux);
// 		aux = ft_strjoin(prev, split[i]);
// 		free(prev);
// 		prev = ft_strdup(aux);
// 		free(aux);
// 		i++;
// 	}
// 	free(ms->prompt.line);
// 	ms->prompt.line = ft_strdup(prev);
// 	free_matrix(split);
// 	free(prev);
// }
