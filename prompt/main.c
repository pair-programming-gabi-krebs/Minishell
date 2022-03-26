/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:25:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/25 22:48:40 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define clear() printf("\033[H\033[J")

int	main(void)
{
	char	*user = getenv("LOGNAME");
	char	*machine = getenv("NAME");
	char	*cwd = getcwd(cwd, 256);
	
	clear();
	while (1)
	{
		printf("%s@%s:%s", user, machine, cwd);
	}
	return 0;
}


