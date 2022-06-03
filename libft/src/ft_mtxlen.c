/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:54:46 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/02 22:24:00 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mtxlen(char **mtx)
{
	int	i;

	if (!mtx)
		return (0);
	i = 0;
	while (mtx[i])
		i++;
	return (i);
}
