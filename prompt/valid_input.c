/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/01 22:51:40 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	valid_input(t_ms *ms)
{
	history(ms, ms->prompt.line);
	pre_token(ms);
	check_special_tokens(ms);
	ms->lexer.line = ft_strdup(ms->tk.line);
	lexer(ms);
	pipeline(ms);
	ft_reset(ms);
}

// echo | tr | grep