/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:16 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/04 21:41:43 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*print_dir(t_ms *ms)
{
	//char	*cwd;
	char	*aux;

	ms->prompt.cwd = ft_calloc(256, sizeof(char));
	ms->prompt.cwd = getcwd(ms->prompt.cwd, 256);
	aux = ft_strjoin("\001\033[1;35m\002Minishell:\001\033[0m\002", ms->prompt.cwd);
	ms->prompt.prompt = ft_strjoin(aux, "$ ");
	free(aux);
	//free(cwd);
	return (ms->prompt.prompt);
}
