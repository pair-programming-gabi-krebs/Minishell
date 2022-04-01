/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:16:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/31 22:23:24 by gcosta-d         ###   ########.fr       */
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
	char	*line;
	char	*infile;
	char	*outfile;
}	t_lexer;


typedef struct s_minishell
{
	t_init		init;
	t_prompt	prompt;
	t_lexer		lexer;
}	t_minishell;


/* Prompt */
char	*print_dir(t_minishell *minishell);
void	prompt(t_minishell *minishell);
void	ft_init(t_minishell *minishell, int argc, char *argv[], char *envp[]);
void	history(char *line);

/* Lexer */
void	lexer(t_minishell *minishell);
void	handle_redirect(t_minishell *minishell);
void	tokenizer(t_minishell *minishell);


#endif