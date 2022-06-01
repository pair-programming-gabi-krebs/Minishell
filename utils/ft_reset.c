/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:36:45 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/31 22:36:29 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_reset(t_ms *ms)
{
	ft_free(ms);
	free_matrix(ms->lexer.tokens);
	free_matrix(ms->cmds.out);
	free_matrix(ms->cmds.inf);
	ms->lexer.i_token = 0;
	ms->lexer.tokens = malloc(2048 * sizeof(char **));
	ms->lexer.tokens[0] = NULL;
	ms->prompt.line = NULL;
	ms->lexer.line = NULL;
	ms->tk.line = NULL;
	ms->cmds.out = malloc(2048 * sizeof(char **));
	ms->cmds.out[0] = NULL;
	ms->cmds.inf = malloc(2048 * sizeof(char **));
	ms->cmds.inf[0] = NULL;
}
