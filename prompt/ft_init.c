/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:32:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/30 21:24:58 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init(t_minishell *minishell, int argc, char *argv[], char *envp[])
{
	minishell->init.argc = argc - 1;
	minishell->init.argv = argv;
	minishell->init.envp = envp;
}
