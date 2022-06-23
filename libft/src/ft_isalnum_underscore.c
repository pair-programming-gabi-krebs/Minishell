/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_underscore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:36:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/22 00:29:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum_underscore(char *s)
{
	while (*s)
	{
		if (!ft_isalpha(*s) && !ft_isdigit(*s) && *s != '_')
			return (0);
		s++;
	}
	return (1);
}
