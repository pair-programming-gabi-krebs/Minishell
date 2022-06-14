/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_set_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 01:46:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/14 01:47:55 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_name_set_count_in(t_ms *ms, char **name, int i, int counter)
{
	get_redirect_name(ms, name, i, counter);
	ms->cmds.inf_counter++;
}

void	get_name_set_count_out(t_ms *ms, char **name, int i, int counter)
{
	get_redirect_name(ms, name, i, counter);
	ms->cmds.out_counter++;
}
