/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/06 23:56:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	valid_input(t_ms *ms)
{
	history(ms, ms->prompt.line);
	pre_token(ms);
	check_special_tokens(ms);
	//ms->lexer.line = ft_strdup(ms->tk.line);
	//cd(ms);
	export(ms, "OI=testinho");
	//env(ms);
	printf("\n\n\n");
	unset(ms, "GJS_DEBUG_TOPICS");
	env(ms);
	//lexer(ms);
	//parser(ms);
	ft_reset(ms);
}
