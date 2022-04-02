/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:18:00 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/04/01 23:52:58 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	special_case(t_ms *ms)
{

}

/*    "l"'s' -la | grep "teste" | tr ' ' a | echo "Hey 'você' !"
 *
 * Sempre que tiver uma aspas ela tem q fechar com a aspas correspondente
 * Assim que identificar uma abertura de aspas, guarda até encontrar uma
 * aspas igual.
 * Se não tiver -> comportamento here_doc
 * Se tiver, verifica próximo byte:
 * Se for espaço, fecha o token na aspas
 * Se não for espaço, junta até achar o espaço e fecha o token
 *
 *
*/

/* V1.0 special_case
void	special_case(t_ms *ms)
{
	int	start_quote;
	int	end_quote;
	int	space;
	int	i;

	i = 0;
	while (1)
	{
		start_quote = strichar(ms->lexer.line, 0, SINGLE_QUOTE);
		end_quote = strichar(ms->lexer.line, start_quote + 1, SINGLE_QUOTE);
		if (end_quote == -1)
			here_doc();
		else if (ms->lexer.line[end_quote + 1] == SPACE)
		{
			ms->lexer.mtx_quote[i] = ft_substr(ms->lexer.line, start_quote,
				end_quote - start_quote);
		}
		else
		{
			space = strichar(ms->lexer.line, end_quote, SPACE);
			ms->lexer.mtx_quote[i] = ft_substr(ms->lexer.line, start_quote,
				space - start_quote);
		}
		i++;
	}
}
*/


