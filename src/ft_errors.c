/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:11 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/19 11:26:47 by deordone         ###   ########.fr       */
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

void	ft_error(t_pipe	*info)
{
	if (info->f_fd != -1)
		close(info->f_fd);
	if (info->l_fd != -1)
		close(info->l_fd);
	if (info->f_file != NULL)
		free(info->f_file);
	if (info->l_file != NULL)
		free(info->l_file);
	if (info->in_cmd != NULL)
		ft_free_array(info->in_cmd);
	if (info->out_cmd != NULL)
		ft_free_array(info->out_cmd);
	if (info->in_path != NULL)
		free(info->in_path);
	if (info->out_path != NULL)
		free(info->out_path);
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_free_array(char **res)
{
	int i;

	i = 0;
	while(res[i])
		i++;
	while (i)
		free(res[i--]);
	free(res[i--]);
	free(res);
}
