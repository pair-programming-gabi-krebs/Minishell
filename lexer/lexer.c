/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:26:23 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/14 02:00:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	lexer(t_ms *ms)
{
	tokenizer(ms);
	remove_quotes(ms);
	check_expand_var(ms);
	if (!syntatic_analysis(ms))
		return (0);
	return (1);
}
