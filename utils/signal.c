/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:56:57 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/10 22:42:26 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int number)
{
	if (number == SIGQUIT)
		return ;
	write(2, "exit\n", 5);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal(t_ms *ms)
{
	ms->signal.sig.sa_handler = &sigint_handler;
	ms->signal.sig.sa_flags = SA_RESTART;
	sigemptyset(&ms->signal.sig.sa_mask);
	sigaddset(&ms->signal.sig.sa_mask, SIGQUIT);
	sigaction(SIGINT, &ms->signal.sig, NULL);
	sigaction(SIGQUIT, &ms->signal.sig, NULL);
}
