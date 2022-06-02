/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:06:45 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/13 00:49:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse_env(t_ms *ms)
{
	ms->cmds.path = ft_strchr(getenv("PATH"), '/');
	ms->cmds.bin = ft_split(ms->cmds.path, ':');
}
