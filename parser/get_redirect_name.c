/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:03 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/03 19:21:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter)
{
	if (ms->cmds.command[i + 1])
	{
		if (redirect[counter])
			free(redirect[counter]);
		redirect[counter] = ft_strdup(ms->cmds.command[i + 1]);
	}
	redirect[counter + 1] = NULL;
}
