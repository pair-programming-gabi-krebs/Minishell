/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:54:33 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/23 21:20:18 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pwd(void)
{
	char	*current_pwd;

	current_pwd = ft_calloc(256, sizeof(char));
	current_pwd = getcwd(current_pwd, 256);
	printf("%s\n", current_pwd);
	free(current_pwd);
}
