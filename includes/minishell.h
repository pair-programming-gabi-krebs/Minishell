/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:16:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/12 21:33:55 by lkrebs-l         ###   ########.fr       */
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

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define FT_SPACE 32

typedef struct sigaction t_sig_action;
typedef sigset_t t_sigset;

typedef struct s_init
{
	char	**argv;
	char	**envp;
	int		argc;
}	t_init;

typedef struct s_prompt
{
	char	*prompt;
	char	*line;
	char	*prev_line;
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

typedef struct s_minishell
{
	t_init				init;
	t_prompt			prompt;
	t_lexer				lexer;
	t_signal			signal;
}	t_ms;


/* Prompt */
char	*print_dir(t_ms *ms);
void	prompt(t_ms *ms);
void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[]);
void	history(t_ms *ms, char *line);
void	ft_signal(t_ms *ms);
void	ft_free(t_ms *ms);
void	free_matrix(char **matrix);
void	ft_reset(t_ms *ms);

/* Lexer */
void	lexer(t_ms *ms);
void	handle_redirect(t_ms *ms);
void	tokenizer(t_ms *ms);
void	common_case(t_ms *ms);
int		special_case(t_ms *ms, char quote, int index);
void	pre_token(t_ms *ms);

/* Parser */
void	pre_parser(t_ms *ms, char *readline);
void	pre_parser2(t_ms *ms);
void	parser(t_ms *ms);

#endif