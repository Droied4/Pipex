/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:08 by deordone          #+#    #+#             */
/*   Updated: 2024/01/18 18:51:13 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
			i++;
		while (--i)
			free(res[i]);
		free(res[i]);
		free(res);
	}
}

void	ft_clean(t_pipe *info)
{
	if (info->f_fd != -1)
		close(info->f_fd);
	if (info->l_fd != -1)
		close(info->l_fd);
	if (info->in_cmd != NULL)
		ft_free_array(info->in_cmd);
	if (info->out_cmd != NULL)
		ft_free_array(info->out_cmd);
	if (info->in_path != NULL)
		free(info->in_path);
	if (info->out_path != NULL)
		free(info->out_path);
	if (info->paths != NULL)
	{
		info->paths[0] -= 5;
		ft_free_array(info->paths);
	}
}

static void	ft_flag5(t_pipe *info)
{
	int	f;

	f = 0;
	if (ft_strncmp(info->in_cmd[0], ".", 1) != 0)
		if (access(info->in_cmd[0], F_OK) != 0)
			if (!info->in_path && ++f != 0)
				ft_dprintf(2, "pipex: command not found: %s\n",
					info->in_cmd[0]);
	if (ft_strncmp(info->out_cmd[0], ".", 1) != 0)
		if (access(info->out_cmd[0], F_OK) != 0)
			if (!info->out_path && ++f != 0)
				ft_dprintf(2, "pipex: command not found: %s\n",
					info->out_cmd[0]);
	if (f != 0)
	{
		ft_clean(info);
		exit(127);
	}
}

void	ft_error(t_pipe *info, const char *message, int flag_nb)
{
	if (flag_nb == 2)
	{
		if (access(info->f_file, F_OK))
			ft_dprintf(2, "pipex: no such file or directory: %s\n", message);
		else
			ft_dprintf(2, "pipex: permission denied: %s\n", message);
	}
	else if (flag_nb == 4)
		ft_dprintf(1, "pipex: %s\n", message);
	else if (flag_nb == 5)
		ft_flag5(info);
	else if (flag_nb == 6)
	{
		ft_dprintf(2, "pipex: command not found: %s\n", message);
		exit(126);
	}
	ft_clean(info);
	exit(0);
}
/*
 * 2 = file errors
 * 3 = just clean
 * 4 = other errors
 * 5 = command not found or permission denied
 * */
