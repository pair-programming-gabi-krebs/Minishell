/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/12 21:31:12 by gcosta-d         ###   ########.fr       */
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
	//parser(ms);
	pipeline(ms);
	//export(ms, "OI=testinho");
	//unset(ms, "HOME");
	//cd(ms);
	//echo(ms);
	//env(ms);
	//pwd();
	//parser(ms);
	ft_reset(ms);
}

// echo | tr | grep