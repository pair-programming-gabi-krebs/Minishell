/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:32:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/27 22:51:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[])
{
	ms->prompt.special = ft_strdup("<>\"\'|");
	ms->init.argc = argc - 1;
	ms->init.argv = argv;
	ms->init.envp = envp;
	ms->lexer.i_token = 0;
	ms->lexer.tokens = malloc(2048 * sizeof(char **));
	ms->lexer.tokens[0] = NULL;
	ms->prompt.line = NULL;
	ms->lexer.line = NULL;
	ms->prompt.prev_line = NULL;
	ms->tk.line = NULL;
	ms->parser.pipes_qtn = 0;
	ft_signal(ms);
}