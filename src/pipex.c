/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2024/01/10 15:04:49 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* auxiliar
void	ft_print_info(t_pipe *info)
{
	ft_printf("\033[1;31mInfo t_pipe\033[0m\n");
	ft_printf("f_file -> %s\n", info->f_file);
	ft_printf("l_file -> %s\n", info->l_file);
	ft_printf("f_fd -> %i\n", info->f_fd);
	ft_printf("l fd -> %i\n", info->l_fd);
	ft_printf("in path -> %s\n", info->in_path);
	ft_printf("out path -> %s\n", info->out_path);
	ft_printf("in cmd -> %s\n", info->in_cmd[0]);
	ft_printf("out cmd -> %s\n", info->out_cmd[0]);
	ft_printf("paths -> %s\n", info->paths[0]);
	ft_printf("\033[1;34mOther procces\033[0m\n");
}*/

void	ft_init_info(t_pipe *info, char **argv, int argc)
{
	info->f_fd = -1;
	info->l_fd = -1;
	info->f_file = argv[1];
	info->l_file = argv[argc - 1];
	info->in_path = NULL;
	info->out_path = NULL;
	info->in_cmd = NULL;
	info->out_cmd = NULL;
	info->paths = NULL;
}

void	ft_extractor(char **argv, t_pipe *info, char *envp[])
{
	int	i;

	info->f_fd = open(info->f_file, O_RDONLY);
	if (info->f_fd == -1)
		ft_error(info, info->f_file, 2);
	info->l_fd = open(info->l_file, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (info->l_fd == -1)
		ft_error(info, "permission dennied: ", 4);
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
}

void	ft_parse_vortex(int argc, char **argv, t_pipe *info, char *envp[])
{
	int	i;

	i = 0;
	ft_init_info(info, argv, argc);
	ft_extractor(argv, info, envp);
	if (ft_handle_access(info) == 1)
		ft_error(info, "handle fail", 5);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	info;

	if (argc < 5 || argc > 5)
	{
		write(1, "incorrect number of arguments\n", 30);
		return (errno);
	}
	ft_parse_vortex(argc, argv, &info, envp);
	ft_vortex(&info);
	return (0);
}
