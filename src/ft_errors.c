/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:08 by deordone          #+#    #+#             */
/*   Updated: 2024/01/03 13:57:33 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	while (--i)
		free(res[i]);
	free(res[i]);
	free(res);
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
		ft_free_array(info->paths);
}

void	ft_error(t_pipe *info, const char *message, int flag_nb)
{
	if (flag_nb == 2)
	{
		if (access(info->f_file, F_OK))
			ft_printf("pipex: no such file or directory: %s\n", message);
		else
			ft_printf("pipex: permission denied: %s\n", message);
	}
	if (flag_nb == 3)
		ft_printf("pipex: command not found: %s\n", message);
	else if (flag_nb == 4)
		ft_printf("pipex: %s", message);
	ft_clean(info);
	exit(EXIT_FAILURE);
}
/* 
 * 2 = archivo no encontrado
 * 3 = comando no encontrado
 * 4 = other errors
 * */
