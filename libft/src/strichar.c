/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strichar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:04:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/27 21:08:19 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strichar(char *string, int pos, char c)
{
	if (!string)
		return (-1);
	while (string[pos] != c && string[pos])
		pos++;
	if ((size_t)pos == ft_strlen(string))
		return (-1);
	return (pos);
}
