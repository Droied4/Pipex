/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:08 by deordone          #+#    #+#             */
/*   Updated: 2024/01/02 09:29:26 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_pipe *info)
{
	close(info->f_fd);
	ft_free_array(info->in_cmd);
	free(info->in_path);
	free(info->out_path);
	ft_free_array(info->out_cmd);
	close(info->l_fd);
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
	else if (flag_nb == 3)
		ft_printf("pipex: command not found: %s\n", message);
	ft_clean(info);
	exit(EXIT_FAILURE);
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
}

void	ft_free_array(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	while (i)
		free(res[i--]);
	free(res[i--]);
	free(res);
}
/*
 * 2 = archivo no encontrado
 * 3 = comando no encontrado
 * */
