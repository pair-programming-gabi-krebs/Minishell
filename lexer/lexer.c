/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:26:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/10 20:49:57 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lexer(t_ms *ms)
{
	tokenizer(ms);
	remove_quotes(ms);
	int j = 0;
	while (j < ms->lexer.i_token)
	{
		printf("token[%d] : %s\n", j, ms->lexer.tokens[j]);
		j++;
	}
}
