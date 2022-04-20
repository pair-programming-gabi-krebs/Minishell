/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/19 23:31:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* static int	end_of_quote(char *string, int i);
static int	chars_length(char *string, int i);
static int	verify_next_bytes(char *string, int i); */
static int	is_special(t_ms *ms, char c);

void	pre_token(t_ms *ms)
{
	int		j;
	int		i;
	int		k;
	int		len;
	char	**matrix;

	i = 0;
	j = 0;
	len = 0;
	k = 0;
	matrix = malloc(10 * sizeof(char **));
	while(ms->prompt.line[i])
	{
		if (is_special(ms, ms->prompt.line[i]))
		{
			printf("k: %d\n", k);
			//len = verify_next_bytes(ms->prompt.line, i);
			printf("len: %d\n", len);
			matrix[j] = ft_substr(ms->prompt.line, k, len);
			len = 1;
			printf("matrix[j] = %s\n", matrix[j]);
			j++;
			k = i;
		}
		len++;
		i++;
	}
}

			/*if (len != 0)
			{
				matrix[j] = ft_substr(ms->prompt.line, i - len, len);
				printf("matrix[%d] %s\n", j, matrix[j]);
				j++;
			} */

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

/* static int	verify_next_bytes(char *string, int i)
{
	int	len;

	len = 0;
	if (string[i] == SINGLE_QUOTE || string[i] == DOUBLE_QUOTE)
		len = end_of_quote(string, i);
	else if (string[i] == '<' || string[i] == '>' || string[i] == '|')
		len = chars_length(string, i);
	return (len);
}

static int	end_of_quote(char *string, int i)
{
	char	character;
	int	j;

	j = 1;
	character = string[i];
	if (string[i + 1] == character)
	{
		j++;
		i++;
	}
	else
	{
		while (string[i + 1] != character)
		{
			j++;
			i++;
		}
	}
	return (j + 1);
}

static int	chars_length(char *string, int i)
{
	char	character;
	int		len;

	len = 1;
	character = string[i];
	while (string[i + 1] == character && string[i + 1])
	{
		i++;
		len++;
	}
	return (len);
}
 */

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
