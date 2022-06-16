/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:56:57 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/16 20:40:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sig_int(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_init_sigaction(t_ms *ms, void (*handler)(int), int sig)
{
	ms->signal.sig.sa_handler = handler;
	ms->signal.sig.sa_flags = SA_RESTART;
	sigemptyset(&ms->signal.sig.sa_mask);
	sigaction(sig, &ms->signal.sig, NULL);
}

void	handle_child_sig_quit(int sig)
{
	(void)sig;
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

void	handle_child_sig_int(int sig)
{
	(void)sig;
	exit(0);
}

void	handle_child_sig_int_here_doc(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
	exit(130);
}
