/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_tokenization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:03:15 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/03 22:03:39 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pre_tokenization(t_ms *ms, int i)
{
	char	*str;
	char	*strdup;

	strdup = ft_strdup(ms->prompt.line);
	strdup[i] = '\0';
	str = ft_substr(strdup, ms->tk.k, ft_strlen(strdup));
	ms->tk.mtx[ms->tk.j] = ft_strdup(str);
	ms->tk.j++;
	ms->tk.k = i;
	free(str);
	free(strdup);
}
