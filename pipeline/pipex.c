/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:51:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/17 22:06:32 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	build_cmd_table(t_ms *ms);
static void	format_table(t_ms *ms, int start, int end);
static void	exec_commands(t_ms *ms, int i);
static void	resolve_dups(t_ms *ms, int i);

void	pipex(t_ms *ms)
{
	int	i;

	parse_env(ms);
	i = -1;
	while (i < ms->parser.pipes_qtn)
	{
		if (i > 0)
		{
			dup2(ms->cmds.fd[0], STDIN_FILENO);
			close(ms->cmds.fd[0]);
		}
		if (pipe(ms->cmds.fd) == -1)
			ft_exit(ms);
		build_cmd_table(ms);
		if (is_builtin(ms))
		{
			exec_builtin(ms);
			i++;
		}
		else
		{
			ms->cmds.pid = fork();
			if (ms->cmds.pid == -1)
				ft_exit(ms);
			if (ms->cmds.pid == 0)
				exec_commands(ms, i);
			else
			{
				waitpid(ms->cmds.pid, &ms->cmds.exit_status, 0);
				close(ms->cmds.fd[1]);
				i++;
			}
		}
	}
	free_matrix(ms->cmds.bin);
	free(ms->cmds.file_path);
	close(ms->cmds.fd[0]);
	close(ms->cmds.fd[1]);
}

static void	build_cmd_table(t_ms *ms)
{
	int	i;
	int	has_format;

	has_format = 0;
	i = ms->cmds.cmd_index;
	while (i < ms->lexer.i_token)
	{
		if (ms->lexer.tokens[i][0] == '|'
			&& ft_strlen(ms->lexer.tokens[i]) == 1)
		{
			format_table(ms, ms->cmds.cmd_index, i);
			has_format = 1;
			i++;
			break ;
		}
		i++;
	}
	if (!has_format)
		format_table(ms, ms->cmds.cmd_index, i);
	ms->cmds.cmd_index = i;
}

static void	format_table(t_ms *ms, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		if (ms->lexer.tokens[start][0] == '>')
		{
			if (ms->cmds.out)
				free(ms->cmds.out);
			ms->cmds.out = ft_strdup(ms->lexer.tokens[start + 1]);
		}
		else if (ms->lexer.tokens[start][0] == '<')
		{
			if (ms->cmds.inf)
				free(ms->cmds.inf);
			ms->cmds.inf = ft_strdup(ms->lexer.tokens[start + 1]);
		}
		else
		{
			ms->cmds.command[j] = ft_strdup(ms->lexer.tokens[start]);
			ms->cmds.command[j + 1] = NULL;
			j++;
		}
		start++;
	}
}

static void	exec_commands(t_ms *ms, int i)
{
	build_cmd_table(ms);
	ms->cmds.file_path = command_finder(ms);
	if (ms->cmds.file_path == NULL)
		ft_exit(ms);
	resolve_dups(ms, i);
	if (execve(ms->cmds.file_path, ms->cmds.command, ms->init.envp) == -1)
		ft_exit(ms);
}

static void	resolve_dups(t_ms *ms, int i)
{
	if (i == ms->parser.pipes_qtn - 1)
		return ;
	else
	{
		dup2(ms->cmds.fd[1], STDOUT_FILENO);
		close(ms->cmds.fd[1]);
	}
}
