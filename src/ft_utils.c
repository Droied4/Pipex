/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:23 by deordone          #+#    #+#             */
/*   Updated: 2024/01/16 11:44:40 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(t_pipe *info, int *pipefd)
{
	if (dup2(info->f_fd, STDIN_FILENO) == -1)
		ft_error(info, "dup2 child failed", 4);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error(info, "dup2 child failed", 4);
	close(pipefd[1]);
	if (execve(info->in_path, info->in_cmd, NULL) < 0)
		ft_error(info, "execve child failed", 4);
	else
		exit(EXIT_SUCCESS);
}

static void	ft_parent(t_pipe *info, int *pipefd)
{
	if (dup2(info->l_fd, STDOUT_FILENO) == -1)
		ft_error(info, "dup parent failed", 4);
	close(info->l_fd);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_error(info, "dup parent failed", 4);
	close(pipefd[0]);
	if (execve(info->out_path, info->out_cmd, NULL) < 0)
		ft_error(info, "execve parent failed", 4);
	else
		exit(EXIT_SUCCESS);
}

void	ft_vortex(t_pipe *info)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		ft_error(info, "pipe failed", 4);
	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed", 4);
	if (pid == 0)
		ft_child(info, pipefd);
	else
		ft_parent(info, pipefd);
}

static char	*ft_aux_check(char *new_path, char *new_cmd)
{
	if (access(new_cmd, F_OK | X_OK) == 0)
		return (new_cmd);
	else if (access(new_cmd, X_OK) == -1)
	{
		free(new_path);
		free(new_cmd);
		return (NULL);
	}
	else
	{
		free(new_path);
		free(new_cmd);
	}
	return (NULL);
}

char	*ft_check_path(t_pipe *info, char **arg_cmd)
{
	int		i;
	int		j;
	char	*new_cmd;
	char	*new_path;

	i = 0;
	j = 0;
	while (info->paths[i] != NULL)
		i++;
	while (i > j)
	{
		new_path = ft_strjoin(info->paths[j], "/");
		new_cmd = ft_strjoin(new_path, arg_cmd[0]);
		new_cmd = ft_aux_check(new_path, new_cmd);
		if (new_cmd)
		{
			free(new_path);
			return (new_cmd);
		}
		j++;
	}
	return (NULL);
}
