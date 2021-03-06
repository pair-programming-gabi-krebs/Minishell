/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:13:41 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/23 21:20:57 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_home(t_ms *ms);
static int	change_dir(t_ms *ms, char *path);
static void	update_pwd_and_oldpwd(t_ms *ms, char *current_pwd);
static int	update_node_content(t_ms *ms, char *current_pwd, t_list *node);

void	cd(t_ms *ms)
{
	char	*path;
	int		return_chdir;

	path = NULL;
	if (check_args(ms))
	{
		write(1, "cd: too many arguments\n", 23);
		return ;
	}
	if (ms->cmds.command[1] && !ft_strncmp(ms->cmds.command[1], "", \
		ft_strlen(ms->cmds.command[1])))
		return ;
	if (is_home(ms))
		path = ft_strdup(getenv("HOME"));
	else if (ms->cmds.command[1] && !ft_strncmp(ms->cmds.command[1], "~/", 2))
		path = handle_home_dir(ms, path);
	else if (ms->cmds.command[1])
		path = ft_strdup(ms->cmds.command[1]);
	return_chdir = change_dir(ms, path);
	if (return_chdir == -1)
		perror("");
	free(path);
}

static int	is_home(t_ms *ms)
{
	int	is_home;

	is_home = 0;
	if (!ms->cmds.command[1])
		is_home = 1;
	else if (ms->cmds.command[1]
		&& (!ft_strncmp(ms->cmds.command[1], "~/", \
		ft_strlen(ms->cmds.command[1]))
			|| !ft_strncmp(ms->cmds.command[1], "~", \
		ft_strlen(ms->cmds.command[1]))))
		is_home = 1;
	return (is_home);
}

static int	change_dir(t_ms *ms, char *path)
{
	int		return_chdir;
	char	*current_pwd;

	return_chdir = -1;
	if (path)
		return_chdir = chdir(path);
	current_pwd = ft_calloc(256, sizeof(char));
	current_pwd = getcwd(current_pwd, 256);
	update_pwd_and_oldpwd(ms, current_pwd);
	return (return_chdir);
}

static void	update_pwd_and_oldpwd(t_ms *ms, char *current_pwd)
{
	t_list	*node;
	int		has_oldpwd;

	node = *(ms->list);
	has_oldpwd = 0;
	while (node->next != NULL)
	{
		has_oldpwd = update_node_content(ms, current_pwd, node);
		node = node->next;
		if (node->next == NULL && !ft_strncmp(node->content, "OLDPWD=", 7))
		{
			free(node->content);
			node->content = ft_strjoin("OLDPWD=", ms->prompt.cwd);
			has_oldpwd = 1;
		}
	}
	if (has_oldpwd == 0)
	{
		node = ft_lstnew(ft_strjoin("OLDPWD=", ms->prompt.cwd));
		ft_lstadd_back(ms->list, node);
	}
	free(current_pwd);
}

static int	update_node_content(t_ms *ms, char *current_pwd, t_list *node)
{
	int	has_oldpwd;

	has_oldpwd = 0;
	if (!ft_strncmp(node->content, "PWD=", 4))
	{
		free(node->content);
		node->content = ft_strjoin("PWD=", current_pwd);
	}
	else if (!ft_strncmp(node->content, "OLDPWD=", 7))
	{
		free(node->content);
		node->content = ft_strjoin("OLDPWD=", ms->prompt.cwd);
		has_oldpwd = 1;
	}
	return (has_oldpwd);
}
