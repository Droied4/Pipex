/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:11 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/18 16:37:44 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_pipe *info)
{
	close(info->f_fd);
	ft_free_array(info->in_cmd);
	ft_free_array(info->out_cmd);
	close(info->l_fd);
}

void	ft_error(void)
{
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
