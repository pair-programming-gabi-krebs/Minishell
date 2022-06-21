/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:32:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/20 21:26:47 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_init_prompt(t_ms *ms);
static void	ft_init_lexer(t_ms *ms);
static void	ft_init_cmd(t_ms *ms);

void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[])
{
	ms->init.envp = envp;
	ms->init.argc = argc - 1;
	ms->init.argv = argv;
	ms->parser.pipes_qtn = 0;
	ms->tk.line = NULL;
	ft_init_cmd(ms);
	ft_init_prompt(ms);
	ft_init_lexer(ms);
	copy_envp(ms);
}

static void	ft_init_prompt(t_ms *ms)
{
	ms->prompt.special = ft_strdup("<>\"\'|");
	ms->prompt.line = NULL;
	ms->prompt.prev_line = NULL;
}

static void	ft_init_lexer(t_ms *ms)
{
	ms->lexer.i_token = 0;
	ms->lexer.tokens = malloc(2048 * sizeof(char **));
	ms->lexer.tokens[0] = NULL;
	ms->lexer.line = NULL;
	ms->lexer.flag_quote = NULL;
}

static void	ft_init_cmd(t_ms *ms)
{
	ms->cmds.cmd_index = 0;
	ms->cmds.command = malloc(100 * sizeof(char *));
	ms->cmds.command[0] = NULL;
	ms->cmds.file_path = NULL;
	ms->cmds.out = malloc(2048 * sizeof(char **));
	ms->cmds.out[0] = NULL;
	ms->cmds.inf = malloc(2048 * sizeof(char **));
	ms->cmds.inf[0] = NULL;
	ms->cmds.bin = NULL;
	ms->cmds.out_fd = -1;
	ms->cmds.inf_fd = -1;
	ms->cmds.exit_status = 0;
	ms->cmds.aux_fd = -1;
	ms->cmds.hdoc_fd = -1;
	ms->cmds.fd[1] = -1;
	ms->cmds.fd[0] = -1;
	ms->cmds.append_flag = 0;
	ms->cmds.limiter = NULL;
	ms->cmds.hdoc_flag = 0;
}
