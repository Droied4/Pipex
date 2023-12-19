/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:31 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/19 11:24:24 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_finit_exec(t_pipe *info, char **argv)
{
	char *new_cmd;

	if(dup2(info->f_fd,0) == -1)
		ft_error(info);
	close(info->f_fd);
	new_cmd = ft_strjoin(" ", info->f_file);
	new_cmd = ft_strjoin(argv[2], new_cmd);
	info->in_cmd = ft_split(new_cmd, ' ');
	execve(info->in_path, info->in_cmd, NULL);
}

void	ft_linit_exec(t_pipe *info, char **argv)
{
	char *new_cmd;

	if(dup2(info->l_fd,0) == -1)
		ft_error(info);
	close(info->l_fd);
	new_cmd = ft_strjoin(" ", info->l_file);
	new_cmd = ft_strjoin(argv[3], new_cmd);
	info->out_cmd = ft_split(new_cmd, ' ');
	execve(info->out_path, info->out_cmd, NULL);
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
#ifdef __linux__
	i += 10;
	ft_strlcpy(new_path, "/usr/bin/", i);
#elif __APPLE__
	i += 6;
	ft_strlcpy(new_path, "/bin/", i);
#endif
	ft_strlcat(new_path, info->in_cmd[0], i);
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
#ifdef __linux__
	i += 10;
	ft_strlcpy(new_path, "/usr/bin/", i);
#elif __APPLE__
	i += 6;
	ft_strlcpy(new_path, "/bin/", i);
#endif
	ft_strlcat(new_path, info->out_cmd[0], i);
	return (new_path);
}
