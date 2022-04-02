/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:29:33 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/01 22:56:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
 * Verificação se tem infile
 * Quantidade de infiles
 * Verificação se tem outfile
 * Quantidade de outfiles
*/
void	handle_redirect(t_ms *ms)
{
	int	infile_redirect;

	infile_redirect = strichar(ms->lexer.line, 0, '<');
	if (infile_redirect != -1)
	{
		while (ms->lexer.line[infile_redirect + 1] == ' ')
			infile_redirect++;

	}
}
