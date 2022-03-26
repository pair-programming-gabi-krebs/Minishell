/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:35:51 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/09/07 21:12:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t lenght)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = s;
	while (i < lenght)
		*(buff + i++) = c;
	return (s);
}
