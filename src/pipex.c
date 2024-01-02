/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2024/01/02 04:38:51 by carmeno          ###   ########.fr       */
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
	printf("paths -> %s\n", info->paths[0]);
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
	info->paths = NULL;
}

void	ft_extractor(int argc, char **argv, t_pipe *info, char *envp[])
{
	int	i;

	info->f_file = argv[1];
	info->l_file = argv[argc - 1];
	info->f_fd = open(info->f_file, O_RDONLY);
	if (info->f_fd == -1)
		ft_error(info, info->f_file, 2);
	info->l_fd = open(info->l_file, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (info->l_fd == -1)
		ft_error(info, "permission dennied: ", 9);
	info->in_cmd = ft_split(argv[2], ' ');
	info->out_cmd = ft_split(argv[3], ' ');
	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			info->paths = ft_split(envp[i], ':');
			break ;
		}
	}
	if (info->paths == NULL)
		info->paths = ft_split("/usr/bin:/bin", ':');
	else
		info->paths[0] = ft_strchr(info->paths[0], '/');
}

void	ft_parse_vortex(int argc, char **argv, t_pipe *info, char *envp[])
{
	ft_init_info(info);
	ft_extractor(argc, argv, info, envp);
	info->in_path = ft_check_path(info, info->in_cmd);
	info->out_path = ft_check_path(info, info->out_cmd);
	if (info->in_path == NULL)
		ft_error(info, info->in_cmd[0], 3);
	else if (info->out_path == NULL)
		ft_error(info, info->out_cmd[0], 3);
	ft_print_info(info);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	info;

	if (argc < 5)
	{
		perror("to less arguments");
		return (errno);
	}
	ft_parse_vortex(argc, argv, &info, envp);
	ft_vortex(&info);
	ft_end(&info);
	return (0);
}
