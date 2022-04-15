/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/15 18:48:13 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	valid_input(t_ms *ms)
{
	history(ms, ms->prompt.line);
	pre_token(ms);
	ms->lexer.line = ft_strdup(ms->prompt.line);
	lexer(ms);
	//parser(ms);
	ft_reset(ms);
}
