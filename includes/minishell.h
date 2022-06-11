/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:16:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/10 23:00:25 by lkrebs-l         ###   ########.fr       */
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
	char	flag_quote;
	int		start_quote;
	int		end_quote;
	int		i_token;
}	t_lexer;

typedef struct s_parser
{
	int		pipes_qtn;
	int		last_redirect;
	char	*infile;
	char	*outfile;
	char	**cmd_table;
	int		out_count;
	int		inf_count;
	int		hdoc_count;
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
	char	**inf;
	char	**out;
	int		inf_fd;
	int		out_fd;
	char	*file_path;
	char	*path;
	char	**bin;
	char	*limiter;
	int		hdoc_fd;
	int		fd[2];
	int		aux_fd;
	int		pid;
	int		exit_status;
	int		cmd_index;
	int		stin;
	int		stout;
	int		append_flag;
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
void	ft_exit(t_ms *ms, int exit_code);
void	ft_reset(t_ms *ms);
void	dup42(int fd, int std);
void	del(void *content);
void	copy_mtx(char **mtx_dest, char **mtx_src, int start, int len);
int		strict_strcmp(const char *s1, const char *s2);

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
void	remove_quotes(t_ms *ms);
void	pre_tokenization(t_ms *ms, int i);
void	line_formater(t_ms *ms);
int		strjoin_quotes(t_ms *ms, int i);
void	strjoin_add_space(t_ms *ms, int i);
void	check_expand_var(t_ms *ms);

/* Parser */
void	get_redirect_name(t_ms *ms, char **redirect, int i, int counter);
void	remove_redirect_from_end_of_str(t_ms *ms);
void	remove_redirect_from_start_of_str(t_ms *ms);
int		check_for_redirects(t_ms *ms);
int		get_last_redirect_position(t_ms *ms, int i);

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
void	exec_builtin(t_ms *ms, int i);
void	exec_commands(t_ms *ms);
void	resolve_dups_outfile(t_ms *ms, int i);
void	resolve_dups_infile(t_ms *ms, int i);
void	format_table(t_ms *ms, int start, int end);
void	build_cmd_table(t_ms *ms);
void	create_process_and_exec_cmd(t_ms *ms, int i);
void	end_pipeline(t_ms *ms);
void	reset_cmd_table(t_ms *ms);
int		handle_redirects(t_ms *ms);
void	here_doc(t_ms *ms);

#endif