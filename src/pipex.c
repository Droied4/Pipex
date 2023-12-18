/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2023/12/18 18:16:43 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_info(t_pipe *info)
{
	printf("\033[1;31mInfo t_pipe\033[0m\n");
	printf("f_fd -> %i\n", info->f_fd);
	printf("l fd -> %i\n", info->l_fd);
	printf("in path -> %s\n", info->in_path);
	printf("out path -> %s\n", info->out_path);
	printf("in cmd -> %s\n", info->in_cmd[0]);
	printf("out cmd -> %s\n", info->out_cmd[0]);
}

int main (int argc, char **argv)
{
	t_pipe	info;
	if (argc < 5)
		exit(1);
	ft_init_info(&info);
	ft_extractor(argc, argv, &info);
	ft_print_info(&info);
	ft_end(&info);
	return (0);
}
