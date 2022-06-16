/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:57:08 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/16 20:42:40 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_error_here_doc(t_ms *ms, int temp_hdoc);
static void	end_here_doc(t_ms *ms, char *line, int fd);

void	here_doc(t_ms *ms)
{
	char	*line;
	int		temp_hdoc;

	ft_init_sigaction(ms, handle_child_sig_int_here_doc, SIGINT);
	ft_init_sigaction(ms, SIG_IGN, SIGQUIT);
	temp_hdoc = open("hdoc_file", O_WRONLY | O_CREAT | O_APPEND, 0744);
	line = readline("> ");
	while (1)
	{
		if (!line)
		{
			print_error_here_doc(ms, temp_hdoc);
			free(ms->cmds.limiter);
			ft_exit(ms, 0);
		}
		if (!ft_strncmp(line, ms->cmds.limiter, ft_strlen(ms->cmds.limiter))
			&& ft_strlen(ms->cmds.limiter) == ft_strlen(line) - 1)
			end_here_doc(ms, line, temp_hdoc);
		write(temp_hdoc, line, ft_strlen(line));
		free(line);
		line = readline("> ");
	}
}

static void	print_error_here_doc(t_ms *ms, int temp_hdoc)
{
	ft_putstr_fd("warning: here-document at line 1 delimited by end-of-file \
		(wanted `", 2);
	ft_putstr_fd(ms->cmds.limiter, 2);
	ft_putstr_fd("')\n", 2);
	close(temp_hdoc);
	ms->cmds.hdoc_fd = open("hdoc_file", O_RDONLY);
}

static void	end_here_doc(t_ms *ms, char *line, int fd)
{
	free(line);
	close(fd);
	ms->cmds.inf_fd = open("hdoc_file", O_RDONLY);
	free(ms->cmds.limiter);
	ft_exit(ms, 0);
}
