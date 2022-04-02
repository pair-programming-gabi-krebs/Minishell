/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:16:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/04/01 23:22:47 by gcosta-d         ###   ########.fr       */
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

# define SINGLE_QUOTE 39
# define DOUBLE_QUOTE 34
# define SPACE 32

typedef struct s_init
{
	char	**argv;
	char	**envp;
	int		argc;
}	t_init;

typedef struct s_prompt
{
	char	*prompt;
}	t_prompt;

typedef struct s_lexer
{
	char	**tokens;
	char	**mtx_quote;
	char	*line;
	char	*infile;
	char	*outfile;
	int		start_quote;
	int		end_quote;
}	t_lexer;


typedef struct s_minishell
{
	t_init		init;
	t_prompt	prompt;
	t_lexer		lexer;
}	t_ms;


/* Prompt */
char	*print_dir(t_ms *ms);
void	prompt(t_ms *ms);
void	ft_init(t_ms *ms, int argc, char *argv[], char *envp[]);
void	history(char *line);

/* Lexer */
void	lexer(t_ms *ms);
void	handle_redirect(t_ms *ms);
void	tokenizer(t_ms *ms);
void	common_case(t_ms *ms);
void	special_case(t_ms *ms);


#endif