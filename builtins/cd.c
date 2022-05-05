/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:13:41 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/05/05 00:05:05 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	update_pwd_and_oldpwd(t_ms *ms, char *current_pwd);

int	cd(t_ms *ms)
{
	/* mock da line do prompt */
	char	**line_mtx;
	line_mtx = ft_split(ms->tk.line, ' ');
	/*						  */

	char	*current_pwd;
	char	*aux;
	int		return_chdir;

	if (!ft_strncmp(line_mtx[1], "~", ft_strlen(line_mtx[1]))
		|| !ft_strncmp(line_mtx[1], "~/", ft_strlen(line_mtx[1])))
		line_mtx[1] = getenv("HOME");
	else if (!ft_strncmp(line_mtx[1], "~/", 2))
	{
		printf("to aqui\n");
		aux = ft_strtrim(ft_strdup(line_mtx[1]), "~");
		free(line_mtx[1]);
		line_mtx[1] = ft_strjoin(getenv("HOME"), aux);
		printf("LINE: %s\n", line_mtx[1]);
		free(aux);
	}
	return_chdir = chdir(line_mtx[1]);
	current_pwd = ft_calloc(256, sizeof(char));
	current_pwd = getcwd(current_pwd, 256);
	update_pwd_and_oldpwd(ms, current_pwd);
	return (return_chdir);
}

static void	update_pwd_and_oldpwd(t_ms *ms, char *current_pwd)
{
	int		mtx_len;
	int		has_oldpwd;
	int		i;

	mtx_len = ft_mtxlen(ms->init.envp);
	has_oldpwd = 0;
	i = 0;
	while (i < mtx_len)
	{
		if (!ft_strncmp(ms->init.envp[i], "PWD=", 4))
			ms->init.envp[i] = ft_strjoin("PWD=", current_pwd);
		else if (!ft_strncmp(ms->init.envp[i], "OLDPWD=", 7))
		{
			ms->init.envp[i] = ft_strjoin("OLDPWD=", ms->prompt.cwd);
			has_oldpwd = 1;
		}
		i++;
	}
	if (has_oldpwd == 0)
	{
		ms->init.envp[i] = ft_strjoin("OLDPWD=", ms->prompt.cwd);
		ms->init.envp[i+1] = NULL;
	}
	free(current_pwd);
}
