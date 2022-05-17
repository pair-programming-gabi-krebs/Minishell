/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:02:03 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/16 22:02:57 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dup42(t_ms *ms, int fd, int std)
{
	int	check;

	check = dup2(fd, std);
	close(fd);
/* 	if (check == -1)
		msg_error(data); */
}
