/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:35:58 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/09/24 22:54:26 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*dst;
	char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	source = (char *)src;
	while (len--)
	{
		*dst++ = *source++;
	}
	return (dest);
}
