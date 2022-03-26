/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:25:46 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/03/25 23:19:23 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#define clear() printf("\033[H\033[J")

void init()
{
    clear();
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t****MY SHELL****");
    printf("\n\n\t-USE AT YOUR OWN RISK-");
    printf("\n\n\n\n*******************"
        "***********************");
    char* username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    sleep(1);
    clear();
}

int	print_dir(void)
{
	char	*cwd = getcwd(cwd, 256);

	printf("MINISHELL:%s$ ", cwd);
	return (1);
}

int takeInput(char* str)
{
    char* buf;

    buf = readline("");
    if (strlen(buf) != 0) {
        strcpy(str, buf);
        return 0;
    } else {
        return 1;
    }
}

int	main(void)
{
	char input[1000];
	int i = 0;
	init();

	while (i < 1)
	{
		print_dir();
		if (takeInput(input))
			continue;
		i++;
	}
	return 0;
}


