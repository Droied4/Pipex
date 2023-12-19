/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:59:31 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/19 18:25:05 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_config_cmd(char *argv, char *file, char **cmd)
{
	char *new_cmd;

	new_cmd = ft_strjoin(" ", file);
	new_cmd = ft_strjoin(argv, new_cmd);
	cmd = ft_split(new_cmd, ' ');
	return (cmd);
}

void	ft_vortex(t_pipe *info)
{
	int pipefd[2];
	int	pid;

	if (pipe(pipefd) == -1)
		ft_error(info);
	pid = fork();
	if (pid == -1)
		ft_error(info);
	if (pid > 0) //father procces
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if(execve(info->in_path, info->in_cmd, NULL))
			ft_error(info);
		exit(EXIT_FAILURE);
	}
	else //child procces
	{
		if (dup2(info->l_fd, STDOUT_FILENO) == -1)
			ft_error(info);
		close(info->l_fd);
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		if (execve(info->out_path, info->out_cmd, NULL))
			ft_error(info);
		exit(EXIT_FAILURE);
	}
}

char	*ft_path_in(t_pipe *info)
{
	char *new_path;
	int i;

	i = 0;
	while (info->in_cmd[0][i] != '\0')
		i++;
	// Aqui tienes que arreglar esto el path tiene que buscarlo a ver si encuentra el comando y cuando lo encuentre cambia el i + 10 y el ifde linux y el elif apple gracias mi vida y mucho animo cuidate precioso. (crear funcion ft_find_path y retorne un string);
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
