/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:57:08 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/10 00:24:22 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_error_here_doc(t_ms *ms, int temp_hdoc);

void	here_doc(t_ms *ms)
{
	char	*line;
	int		temp_hdoc;

	temp_hdoc = open("hdoc_file", O_WRONLY | O_CREAT | O_APPEND, 0744);
	line = get_next_line(STDIN_FILENO);
	while (1)
	{
		if (!line)
		{
			print_error_here_doc(ms, temp_hdoc);
			break ;
		}
		if (!ft_strncmp(line, ms->cmds.limiter, ft_strlen(ms->cmds.limiter))
			&& ft_strlen(ms->cmds.limiter) == ft_strlen(line) - 1)
		{
			free(line);
			close(temp_hdoc);
			ms->cmds.hdoc_fd = open("hdoc_file", O_RDONLY);
			break ;
		}
		write(temp_hdoc, line, ft_strlen(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
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