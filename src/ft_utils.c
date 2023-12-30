/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:23 by deordone          #+#    #+#             */
/*   Updated: 2023/12/30 20:32:57 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			if (ft_find_path(info, info->in_cmd) == 0)
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
			if (ft_find_path(info, info->out_cmd) == 0)
				exit(EXIT_SUCCESS);
			else
				ft_error(info, "command not found");
		}
		exit(EXIT_FAILURE);
	}
}

int	ft_find_path(t_pipe *info, char **arg_cmd)
{
	int		i;
	int		j;
	char	*new_path;

	i = 0;
	j = 0;
	while (info->paths[i] != NULL)
		i++;
	while (i > j)
	{
		new_path = ft_strjoin(info->paths[j], "/");
		new_path = ft_strjoin(new_path, arg_cmd[0]);
		if (execve(new_path, arg_cmd, NULL) == -1)
			j++;
		else
			return (0);
	}
	return (1);
}
