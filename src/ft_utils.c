/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:31 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/18 18:03:52 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_init_info(t_pipe *info)
{
        info->f_fd = -1;
        info->l_fd = -1;
        info->in_path = NULL;
	info->out_path = NULL;
        info->in_cmd = NULL;
        info->out_cmd = NULL;
}

void    ft_extractor(int argc, char **argv, t_pipe *info)
{
        info->f_fd = open(argv[1], O_RDONLY);
        info->l_fd = open(argv[argc - 1], O_RDONLY);
        if ((info->f_fd == -1) | (info->l_fd == -1))
                ft_error(info);
	info->in_cmd = ft_split(argv[2], ' ');
        info->out_cmd = ft_split(argv[3], ' ');
	info->in_path = ft_path_in(info);
	info->out_path = ft_path_out(info);
}

char	*ft_path_in(t_pipe *info)
{
	char *new_path;
	int i;

	i = 0;
	while (info->in_cmd[0][i] != '\0')
		i++;
	new_path = malloc(sizeof(char) * i + 10);
	if (new_path == NULL)
		ft_error(info);
	ft_strlcpy(new_path, "/usr/bin/", i + 10);
	ft_strlcat(new_path, info->in_cmd[0], i + 10);
	return (new_path);
}

char	*ft_path_out(t_pipe *info)
{
	char *new_path;
	int i;

	i = 0;
	while (info->out_cmd[0][i] != '\0')
		i++;
	new_path = malloc(sizeof(char) * i + 10);
	if (new_path == NULL)
		ft_error(info);
	ft_strlcpy(new_path, "/usr/bin/", i + 10);
	ft_strlcat(new_path, info->out_cmd[0], i + 10);
	return (new_path);
}
