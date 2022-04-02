/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:32:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/02 18:54:34 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[])
{
	ms->init.argc = argc - 1;
	ms->init.argv = argv;
	ms->init.envp = envp;
	ms->lexer.i_token = 0;
}
