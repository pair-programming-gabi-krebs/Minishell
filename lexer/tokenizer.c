/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:30:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/03/31 23:24:39 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenizer(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->lexer.line[i])
	{
		if (minishell->lexer.line[i] == '<' || minishell->lexer.line[i] == '>')
			handle_redirect(minishell);
		else if (minishell->lexer.line[i] == '$')
			handle_vars(minishell);
		else if (minishell->lexer.line[i] == '<'
			&& minishell->lexer.line[i + 1] == '<')
			handle_delimiter(minishell);
		else if (minishell->lexer.line[i] == '>'
			&& minishell->lexer.line[i + 1] == '>')
			handle_append(minishell);
		else if (minishell->lexer.line[i] == '\''
			|| minishell->lexer.line[i] == '"')
			handle_quotes(minishell);
		else if (ft_isalpha(minishell->lexer.line[i]))
			handle_cmds(minishell);
		i++;
	}
}

/* [ COMANDO ] echo "e<e"     <   README.md
 * 	| depois de um comando, sempre vem uma option se começar com
 * 	| caracter alfabético, - ou aspas.
 * 	|
 * [ REDIRECT ] <infile  OU   > outfile
 * 	| depois de um caracter de redirect, sempre vem o nome do arquivo
 * 	|
 * [ DELIMITER ] << LIMITER
 * 	| depois de um caracter de delimitação sempre vem a palavra delimitadora
 * 	|
 * [ APPEND ] >>
 * 	|
 * [ ASPAS ] "l"s    OU   'l's
 * 	| depois de aspas quase sempre vem algo para ser tratado como string
 * 	|
 * [ $ ] $ARGS
 * 	|
 * [ SPACE ]           ls -la
 * 	| pode receber qualquer coisa depois dele
 *
 *
 *
 * <   README.md echo               "e<e"
 * REDIRECT_IN CMD OPTION
 * <README.md echo "e<e"
*/