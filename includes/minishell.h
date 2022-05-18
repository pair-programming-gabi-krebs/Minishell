/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:16:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/05/17 21:49:34 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define FT_SPACE 32

typedef struct sigaction	t_sig_action;

typedef sigset_t			t_sigset;

typedef struct s_init
{
	char	**argv;
	char	**envp;
	int		argc;
}	t_init;

typedef struct s_prompt
{
	char	*special;
	char	*prompt;
	char	*line;
	char	*prev_line;
	char	*cwd;
	char	**cpy_envp;
}	t_prompt;

typedef struct s_signal
{
	t_sig_action		sig;
	t_sigset			set;
}	t_signal;

typedef struct s_lexer
{
	char	**tokens;
	char	*line;
	char	*infile;
	char	*outfile;
	int		start_quote;
	int		end_quote;
	int		i_token;
}	t_lexer;

typedef struct s_parser
{
	int		pipes_qtn;
	char	*infile;
	char	*outfile;
	//char	**cmds;
	char	**cmd_table;
}	t_parser;

typedef struct s_tk
{
	char	**mtx;
	char	*line;
	int		j;
	int		k;
	int		len;
}	t_tk;

typedef struct s_echo
{
	char	*line;
}	t_echo;

typedef struct s_cmds
{
	char	**command;
	char	*inf;
	char	*out;
	char	*file_path;
	char	*path;
	char	**bin;
	int		fd[2];
	int		pid;
	int		exit_status;
	int		cmd_index;
}	t_cmds;

typedef struct s_minishell
{
	t_init		init;
	t_prompt	prompt;
	t_lexer		lexer;
	t_signal	signal;
	t_parser	parser;
	t_tk		tk;
	t_echo		echo;
	t_list		**list;
	t_cmds		cmds;
	//t_list		**tk_list;
}	t_ms;

/* Prompt */
char	*print_dir(t_ms *ms);
void	prompt(t_ms *ms);
void	history(t_ms *ms, char *line);
void	free_matrix(char **matrix);
void	valid_input(t_ms *ms);

/* Utils */
void	copy_envp(t_ms *ms);
void	ft_signal(t_ms *ms);
void	ft_free(t_ms *ms);
void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[]);
void	ft_exit(t_ms *ms);
void	ft_reset(t_ms *ms);
void	dup42(int fd, int std);

/* Lexer */
void	lexer(t_ms *ms);
void	tokenizer(t_ms *ms);
int		special_case(t_ms *ms, char quote, int index);
void	pre_token(t_ms *ms);
void	check_special_tokens(t_ms *ms);
int		is_special(t_ms *ms, char c);
void	make_substr_and_increment(t_ms *ms, int i, int len);
int		handle_next_special_bytes(t_ms *ms, int i);
int		handle_quote(t_ms *ms, int i, char chr);
int		syntatic_analysis(t_ms *ms);
void	remove_quotes(t_ms *ms);

/* Parser */
void	parser(t_ms *ms);

/* Builtins */
int		cd(t_ms *ms);
void	env(t_ms *ms);
void	unset(t_ms *ms, char *var);
void	export(t_ms *ms, char *var);
void	echo(t_ms *ms);
void	pwd(void);

/* Pipeline */
void	pipeline(t_ms *ms);
void	pipex(t_ms *ms);
char	*command_finder(t_ms *ms);
void	parse_env(t_ms *ms);
int		is_builtin(t_ms *ms);
void	exec_builtin(t_ms *ms);

void	del(void *content);

#endif