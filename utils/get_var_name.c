/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:26:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/22 01:26:56 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_var_name(char *content)
{
	int		equals_index;

	equals_index = strichar(content, 0, '=');
	return (ft_substr(content, 0, equals_index + 1));
}
