/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:23 by deordone          #+#    #+#             */
/*   Updated: 2023/12/23 11:42:15 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_config_cmd(char *argv, char *file, char **cmd)
{
	char	*new_cmd;

	new_cmd = ft_strjoin(" ", file);
	new_cmd = ft_strjoin(argv, new_cmd);
	cmd = ft_split(new_cmd, ' ');
	return (cmd);
}

void	ft_vortex(t_pipe *info)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		ft_error(info, "pipe failed");
	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed");
	if (pid > 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execve(info->in_path, info->in_cmd, NULL) == -1)
		{
			if (ft_find_path(info->in_cmd) == 0)
				exit(EXIT_SUCCESS);
			else
				ft_error(info, "command not found");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		if (dup2(info->l_fd, STDOUT_FILENO) == -1)
			ft_error(info, "dup child failed");
		close(info->l_fd);
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			ft_error(info, "dup child failed");
		close(pipefd[0]);
		if (execve(info->out_path, info->out_cmd, NULL) == -1)
		{
			if (ft_find_path(info->out_cmd) == 0)
				exit(EXIT_SUCCESS);
			else
				ft_error(info, "command not found");
		}
		exit(EXIT_FAILURE);
	}
}

int	ft_find_path(char **arg_cmd)
{
	int		i;
	int		j;
	int		l_path;
	char 	*my_path;
	char	**split_path;
	char	*rslt_path;
	char	PATH_VALUE[] = "/Users/deordone/.deno/bin:/Users/deordone/Library/Python/3.8/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/usr/local/go/bin:/usr/local/munki"; 

	i = 0;
	j = 0;
	l_path = ft_strlen(PATH_VALUE);
	my_path = malloc(sizeof(char) * (l_path + 1));
	ft_strlcpy(my_path, PATH_VALUE, l_path + 1);
	split_path = ft_split(my_path, ':');
	while(split_path[i] != NULL)
		i++;
	while (i > j)
	{
		my_path = ft_strjoin(split_path[j], "/");
		rslt_path = ft_strjoin(my_path, arg_cmd[0]);
		if (execve(rslt_path, arg_cmd, NULL) == -1)
			j++;
		else 
			return (0);
	}
	return (1);
}
/*
char	*ft_path_in(t_pipe *info)
{
	char	*new_path;
	int		i;

	i = 0;
	while (info->in_cmd[0][i] != '\0')
		i++;
	new_path = malloc(sizeof(char) * i + 10);
	if (new_path == NULL)
		ft_error(info, "malloc failed");
#ifdef __LINUX__
	i += 10;
	ft_strlcpy(new_path, "/usr/bin/", i);
#elif __APPLE__
	i += 6;
	ft_strlcpy(new_path, "/bin/", i);
#endif
	ft_strlcat(new_path, info->in_cmd[0], i);
	return (new_path);
}

char	*ft_path_out(t_pipe *info)
{
	char	*new_path;
	int		i;

	i = 0;
	while (info->out_cmd[0][i] != '\0')
		i++;
	new_path = malloc(sizeof(char) * i + 10);
	if (new_path == NULL)
		ft_error(info, "malloc failed");
#ifdef __LINUX__
	i += 10;
	ft_strlcpy(new_path, "/usr/bin/", i);
#elif __APPLE__
	i += 6;
	ft_strlcpy(new_path, "/bin/", i);
#endif
	ft_strlcat(new_path, info->out_cmd[0], i);
	return (new_path);
}*/
