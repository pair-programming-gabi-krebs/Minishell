/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:13:41 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/03 23:21:33 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd(t_ms *ms)
{
	char	**line_mtx;
	int		return_value;

	line_mtx = ft_split(ms->tk.line, ' ');
	return_value = chdir(line_mtx[1]);
	printf("PWD: %s\n", getenv("PWD"));

	return (return_value);
}

/*
	Confere se só existe 2 argumentos: cd e o path
*/