/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/15 22:36:04 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pre_token(t_ms *ms)
{
	int		j;
	int		i;
	int		len;
	char	**matrix;

	i = 0;
	j = 0;
	len = 0;
	while(ms->prompt.line[i])
	{
		if (is_special(ms, ms->prompt.line[i]))
		{
			matrix[j] = ft_substr(ms->prompt.line, i - len, len);
			j++;
			len = funcao();
			if (len != 0)
			{
				matrix[j] = ft_substr(ms->prompt.line, i - len, len);
				j++;
			}
		}
		len++;
		i++;
	}
}

static int	verify_next_bytes(t_ms *ms)
{
	
}
// banana <<<da"terra <"<ruim
// j = 1;
// i = 8;
// len = 1;
// matrix[0] = "banana ";
// matrix[1] = "<<<"
// matrix[2] = "<"
// matrix[3] = "<"

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
