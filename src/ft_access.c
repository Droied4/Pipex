/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:04:21 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/12 19:59:45 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_file_taster(char *cmd)
{
	if ((access(cmd, F_OK | X_OK)) == 0)
		return (3);
	else if ((access(cmd, F_OK)) == 0)
	{
		ft_printf("pipex: permission denied: %s\n", cmd);
		return (2);
	}
	else
	{
		ft_printf("pipex: no such file or directory: %s\n", cmd);
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
	if (exit_status == 3)//si salio bien lo actualizamos
		ft_aux_taster(info, 0, 0, info->in_cmd);
	if (ft_strncmp(info->out_cmd[0], ".", 1) == 0)
		parent_aux = ft_file_taster(info->out_cmd[0]);
	if (parent_aux == 3 && exit_status == 3)//si el padre salio bien con el . devolvemos
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

	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed", 4);
	if (pid == 0)
		child_process(info, pid);
	else
		rslt = parent_process(info, pid);
	return (rslt);
}
