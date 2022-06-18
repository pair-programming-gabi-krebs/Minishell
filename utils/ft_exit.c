/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:34:24 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/18 10:26:07 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit(t_ms *ms, int exit_code)
{
	rl_clear_history();
	printf("\n");
	free_matrix(ms->lexer.tokens);
	if (ms->cmds.command)
		free_matrix(ms->cmds.command);
	free(ms->prompt.prev_line);
	free(ms->cmds.file_path);
	free(ms->prompt.special);
	free_matrix(ms->cmds.out);
	free_matrix(ms->cmds.inf);
	if (ms->cmds.bin)
		free_matrix(ms->cmds.bin);
	ft_lstclear(ms->list, free);
	ft_free(ms);
	exit(exit_code);
}
