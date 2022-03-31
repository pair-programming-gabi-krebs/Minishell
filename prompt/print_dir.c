/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:16 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/30 21:21:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*print_dir(t_minishell *minishell)
{
	char	*cwd;
	char	*aux;

	cwd = ft_calloc(256, sizeof(char));
	cwd = getcwd(cwd, 256);
	aux = ft_strjoin("Minishell:", cwd);
	minishell->prompt.prompt = ft_strjoin(aux, "$ ");
	free(aux);
	free(cwd);
	return (minishell->prompt.prompt);
}
