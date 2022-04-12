/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:07:32 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/11 21:46:11 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *string, char c)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	pos = strichar(string, pos, c);
	while (pos != -1)
	{
		pos = strichar(string, pos, c);
		count ++;
	}
	return (count);
}
