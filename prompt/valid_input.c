/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/05 16:37:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	valid_input(t_ms *ms)
{
	history(ms, ms->prompt.line);
	pre_token(ms);
	check_special_tokens(ms);
	//ms->lexer.line = ft_strdup(ms->tk.line);
	copy_envp(ms);
	export(ms, "DASASD=DASASD");
	env(ms);
	//cd(ms);
	//lexer(ms);
	//parser(ms);
	ft_reset(ms);
}
