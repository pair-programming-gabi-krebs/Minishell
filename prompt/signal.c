/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:56:57 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/06 03:37:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void sigint_handler(int number)
{
	(void)number;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal(t_ms *ms)
{
	ms->signal.sig.sa_handler = sigint_handler;
	sigemptyset(&ms->signal.sig.sa_mask);
	sigaddset(&ms->signal.sig.sa_mask, SIGTSTP);
	sigaddset(&ms->signal.sig.sa_mask, SIGQUIT);
	sigaction(SIGINT, &ms->signal.sig, NULL);
}