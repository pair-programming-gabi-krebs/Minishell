/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strict_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:48:32 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/09 20:45:55 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	strict_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	else if ((!s1 && s2) || (s1 && !s2))
		return (1);
	else if (!ft_strncmp(s1, s2, ft_strlen(s1))
		&& !ft_strncmp(s1, s2, ft_strlen(s2))
		&& ft_strlen(s1) == ft_strlen(s2))
		return (0);
	return (1);
}
