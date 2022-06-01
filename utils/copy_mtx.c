/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_mtx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:00:41 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/31 22:25:00 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	copy_mtx(char **mtx_dest, char **mtx_src, int start, int len)
{
	int	i;

	i = 0;
	if ((!mtx_dest && !mtx_src) || !mtx_src)
		return ;
	while (mtx_src[start] && i < len)
	{
		mtx_dest[i] = ft_strdup(mtx_src[start]);
		start++;
		i++;
	}
	mtx_dest[i] = NULL;
	free_matrix(mtx_src);
}
