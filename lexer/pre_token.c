/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:09:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/11 23:37:55 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pre_token(t_ms *ms)
{
	if (ft_strchr(ms->prompt.line, '|'))
		handle_pipe(ms);
}

void	handle_pipe(t_ms *ms)
{
	char	**split;
	char	*prev;
	char	*aux;
	int		i;

	split = ft_split(ms->prompt.line, '|');
	prev = ft_strdup(split[0]);
	i = 0;
	while (i < ft_mtxlen(split))
	{
		aux = ft_strjoin(prev, " | ");
		free(prev);
		prev = ft_strdup(aux);
		free(aux);
		aux = ft_strjoin(prev, split[i + 1]);

		i++;
	}
}

// ls<out|wc -l | grep "test"
//
// 2. split por pipe
// ls<out
// wc -l
// grep "test"
// 3. strjoin (split[0], " | ")
// ls<out |
// 4. strjoin (ls<out | , split[1])
// ls<out | wc -l
// 5. strjoin (ls<out | wc -l, " | ")
// ls<out | wc -l |
// 6. strjoin (ls<out | wc -l | , split[2])
//
// ls<out | wc -l | grep "test"
// 7. split por redirect
// ls
// out | wc -l | grep "test"
// 8. strjoin (split[0], " < ")
// ls <
// 9. strjoin (ls < , split[1])
// ls < out | wc -l | grep "test"