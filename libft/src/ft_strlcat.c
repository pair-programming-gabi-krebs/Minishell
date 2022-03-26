/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:46:04 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/09/07 22:08:52 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_lenght;
	size_t	src_lenght;

	dest_lenght = ft_strlen(dst);
	src_lenght = ft_strlen(src);
	i = 0;
	j = dest_lenght;
	if (dest_lenght < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dest_lenght + i < dstsize - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dest_lenght >= dstsize)
		dest_lenght = dstsize;
	return (dest_lenght + src_lenght);
}
