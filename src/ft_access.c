/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:15:49 by deordone          #+#    #+#             */
/*   Updated: 2024/01/16 12:03:59 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_file_taster(char *cmd)
{
	if ((access(cmd, F_OK | X_OK)) == 0)
		return (3);
	else if ((access(cmd, F_OK)) == 0)
	{
		ft_dprintf(2, "pipex: permission denied: %s\n", cmd);
		return (2);
	}
	else
	{
		ft_dprintf(2, "pipex: no such file or directory: %s\n", cmd);
		return (1);
	}
}

static int	ft_aux_taster(t_pipe *info, int aux, int pid, char **cmd)
{
	if (aux == 3)
	{
		if (pid == 0)
			info->in_path = cmd[0];
		else if (pid != 0)
			info->out_path = cmd[0];
		return (3);
	}
	else
	{
		if (pid == 0)
			info->in_path = ft_check_path(info, cmd);
		else
			info->out_path = ft_check_path(info, cmd);
		if (ft_check_path(info, cmd) == NULL)
			return (1);
		else
			return (3);
	}
}

static int	parent_process(t_pipe *info, int pid)
{
	int	exit_status;
	int	parent_aux;

	parent_aux = 0;
	exit_status = 0;
	waitpid(0, &parent_aux, 0);
	if (WIFEXITED(parent_aux))
		exit_status = WEXITSTATUS(parent_aux);
	if (exit_status == 3)
		ft_aux_taster(info, 0, 0, info->in_cmd);
	if (ft_strncmp(info->out_cmd[0], ".", 1) == 0)
		parent_aux = ft_file_taster(info->out_cmd[0]);
	if (parent_aux == 3 && exit_status == 3)
		return (parent_aux);
	else if (parent_aux != 3)
		parent_aux = ft_aux_taster(info, parent_aux, pid, info->out_cmd);
	return (parent_aux);
}

static void	child_process(t_pipe *info, int pid)
{
	int	child_aux;

	child_aux = 0;
	if (ft_strncmp(info->in_cmd[0], ".", 1) == 0)
		child_aux = ft_file_taster(info->in_cmd[0]);
	if (child_aux == 3 || child_aux == 2)
		exit(child_aux);
	else
		child_aux = ft_aux_taster(info, child_aux, pid, info->in_cmd);
	if (child_aux == 3)
		exit(child_aux);
	else
		exit(child_aux);
}

int	ft_handle_access(t_pipe *info)
{
	int	pid;
	int	rslt;

	rslt = 0;
	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed", 4);
	if (pid == 0)
		child_process(info, pid);
	else
		rslt = parent_process(info, pid);
	return (rslt);
}
