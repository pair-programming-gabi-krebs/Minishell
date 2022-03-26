/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:36:41 by lkrebs-l          #+#    #+#             */
/*   Updated: 2021/09/06 22:22:48 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	size_t	lenght;

	lenght = ft_strlen(string) + 1;
	while (lenght--)
	{
		if (string[lenght] == (unsigned char)c)
			return ((char *) string + lenght);
	}
	return (NULL);
}
