/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:34 by gcosta-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 16:37:22 by lkrebs-l         ###   ########.fr       */
=======
/*   Updated: 2022/05/12 21:31:12 by gcosta-d         ###   ########.fr       */
>>>>>>> gabidev/builtins
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	valid_input(t_ms *ms)
{
	history(ms, ms->prompt.line);
	pre_token(ms);
	check_special_tokens(ms);
<<<<<<< HEAD
	//ms->lexer.line = ft_strdup(ms->tk.line);
	copy_envp(ms);
	export(ms, "DASASD=DASASD");
	env(ms);
	//cd(ms);
	//lexer(ms);
=======
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
>>>>>>> gabidev/builtins
	//parser(ms);
	ft_reset(ms);
}

// echo | tr | grep