/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:17:40 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/01 22:56:38 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	common_case(t_ms *ms)
{
	ms->lexer.tokens = ft_split(ms->lexer.line, ' ');
	for (int i = 0; i < 10; i++)
	{
		printf("[%d] %s\n", i, ms->lexer.tokens[i]);
	}
}

/* ls -la | wc -l > infline <outfile | agh$f<
 *
 * [0] ls
 * [1] -la
 * [2] |
 * [3] wc
 * [4] -l
 * [5] >
 * [6] infile
 * [7] <outfile
 * [8] |
 * [9] agh$f<
 *
*/