/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:25:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/30 21:24:03 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define clear() printf("\033[H\033[J")

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	minishell;

	ft_init(&minishell, argc, argv, envp);
	prompt(&minishell);
	return (0);
}
