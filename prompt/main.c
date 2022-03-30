/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:25:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/29 23:15:19 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define clear() printf("\033[H\033[J")

int	main(int argc, char *argv[], char *envp[])
{
	t_init init;

	ft_init(&init, argc, argv, envp);
	prompt();
	return (0);
}


