/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:16 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/02 22:44:36 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*print_dir(t_ms *ms)
{
	char	*aux;

	ms->prompt.cwd = ft_calloc(256, sizeof(char));
	ms->prompt.cwd = getcwd(ms->prompt.cwd, 256);
	aux = ft_strjoin("\001\033[1;35m\002Minishell:\001\033[0m\002", ms->prompt.cwd);
	ms->prompt.prompt = ft_strjoin(aux, "$ ");
	free(aux);
	return (ms->prompt.prompt);
}
