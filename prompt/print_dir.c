/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:45:16 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/29 23:18:51 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	print_dir(void)
{
	char	*cwd;

	cwd = malloc(256 * sizeof(char));
	cwd = getcwd(cwd, 256);

	printf("MINISHELL:%s", cwd);
	free(cwd);
	return (1);
}
