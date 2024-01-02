/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:23 by deordone          #+#    #+#             */
/*   Updated: 2024/01/02 10:08:59 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_child(t_pipe *info, int *pipefd)
{
	if (dup2(info->f_fd, STDIN_FILENO) == -1)
		ft_error(info, "dup2 kid faile", 4);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_error(info, "dup2 kid failed", 4);
	close(pipefd[1]);
	if (execve(info->in_path, info->in_cmd, NULL) < 0)
		ft_error(info, "execve failed", 1);
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
		ft_error(info, "execve failed", 1);
	else
		exit(EXIT_SUCCESS);
}

void	ft_vortex(t_pipe *info)
{
	int	pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		ft_error(info, "pipe failed", 5);
	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed", 6);
	if (pid == 0)
		ft_child(info, pipefd);
	else
		ft_parent(info, pipefd);
}

char	*ft_check_path(t_pipe *info, char **arg_cmd)
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
		if (access(new_path, F_OK) == -1)
			j++;
		else
			return (new_path);
	}
	return (NULL);
}
