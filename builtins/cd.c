/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:13:41 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/04 21:44:53 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd(t_ms *ms)
{
	char	**line_mtx;
	char	*current_wd;
	int		return_value;

	line_mtx = ft_split(ms->tk.line, ' ');
	return_value = chdir(line_mtx[1]);
	current_wd = ft_calloc(256, sizeof(char));
	current_wd = getcwd(current_wd, 256);
	printf("PWD: %s\n", current_wd);
	printf("OLDPWD: %s\n", ms->prompt.cwd);

	return (return_value);
}

/*
	Confere se só existe 2 argumentos: cd e o path
*/