/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:48:41 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/10 18:01:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pre_parser(t_ms *ms, char *readline)
{
	
	
	ms->prompt.line = readline;
}

/*
 tratativas:
	setinha de maior e menor coladas
	<infile >outfile -----	< infile > outfile

	coisa escrito antes e depois dos redirects
	wc<parser.c -l | wc -l parser.c>outfile
	pipe sem espaço
	ls|wc -l -----	ls | wc -l


*/