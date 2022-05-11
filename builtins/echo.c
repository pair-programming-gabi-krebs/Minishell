/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:08:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/11 20:49:53 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(t_ms *ms)
{
	/* mock da line do prompt */
	char	**line_mtx;
	line_mtx = split_special(ms->tk.line);
	/*						  */
	int	has_nl;
	int	i;

	has_nl = 1;
	if (!ft_strncmp(line_mtx[1], "-n", ft_strlen(line_mtx[1])))
		has_nl = 0;
	if (has_nl)
	{
		i = 0;
		while (line_mtx[++i])
			printf("%s\n", line_mtx[i]);
	}
	else
	{
		i = 1;
		while (line_mtx[++i])
			printf("%s", line_mtx[i]);
	}
}

char	**split_special(char *line)
{
	char **mtx;

	

	return (mtx);

}

/*
	[ ] Verificar se há -n
	[ ] Verificar se há $
	[ ] Verificar se há single quote
	[ ] Verificar se há double quote
*/