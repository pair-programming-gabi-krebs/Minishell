/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:34:24 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/05 20:14:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_ms *ms)
{
	printf("\n");
	free_matrix(ms->lexer.tokens);
	free(ms->prompt.prev_line);
	free(ms->prompt.special);
	free_matrix(ms->prompt.cpy_envp);
	ft_free(ms);
	exit(1);
}
