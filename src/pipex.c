/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2023/12/18 16:26:58 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_info(t_pipe *info)
{
	printf("Info t_pipe\n");
	printf("%i\n", info->f_fd);
	printf("%i\n", info->l_fd);
	printf("%s\n", info->in_cmd[0]);
	printf("%s\n", info->out_cmd[0]);
}

void	ft_extractor(int argc, char **argv, t_pipe *info)
{
	info->f_fd = open(argv[1], O_RDONLY);
	info->l_fd = open(argv[argc - 1], O_RDONLY);
	if ((info->f_fd == -1) | (info->l_fd == -1))
		ft_error();
	info->in_cmd = ft_split(argv[2], ' ');
	info->out_cmd = ft_split(argv[3], ' ');
	//buscar dentro den /bin/ el comando de in
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
