/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2023/12/19 18:29:12 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_info(t_pipe *info)
{
	printf("\033[1;31mInfo t_pipe\033[0m\n");
	printf("f_file -> %s\n", info->f_file);
	printf("l_file -> %s\n", info->l_file);
	printf("f_fd -> %i\n", info->f_fd);
	printf("l fd -> %i\n", info->l_fd);
	printf("in path -> %s\n", info->in_path);
	printf("out path -> %s\n", info->out_path);
	printf("in cmd -> %s\n", info->in_cmd[0]);
	printf("out cmd -> %s\n", info->out_cmd[0]);
	printf("\033[1;34mOther procces\033[0m\n");
}

void	ft_init_info(t_pipe *info)
{
	info->f_fd = -1;
	info->l_fd = -1;
	info->f_file = NULL;
	info->l_file = NULL;
	info->in_path = NULL;
	info->out_path = NULL;
	info->in_cmd = NULL;
	info->out_cmd = NULL;
}

void	ft_extractor(int argc, char **argv, t_pipe *info)
{
	info->f_file = argv[1];
	info->l_file = argv[argc - 1];
	info->f_fd = open(info->f_file, O_RDONLY);
	info->l_fd = open(info->l_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if ((info->f_fd == -1) | (info->l_fd == -1))
		ft_error(info);
	info->in_cmd = ft_split(argv[2], ' ');
	info->out_cmd = ft_split(argv[3], ' ');
	info->in_path = ft_path_in(info);
	info->out_path = ft_path_out(info);
}

int	main(int argc, char **argv)
{
	t_pipe	info;

	if (argc < 5)
		exit(1);
	ft_init_info(&info);
	ft_extractor(argc, argv, &info);
	ft_print_info(&info);
	info.in_cmd  = ft_config_cmd(argv[2], info.f_file, info.in_cmd);
	ft_vortex(&info);
	//ft_end(&info);
	return (0);
}
