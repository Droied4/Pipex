/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:30:08 by deordone          #+#    #+#             */
/*   Updated: 2024/01/12 18:15:57 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
int	ft_handle_access(t_pipe *info)
{
	int	pid;
	int	child_aux;
	int cmp_aux;

	cmp_aux = 0;
	child_aux = 0;
	pid = fork();
	if (pid == -1)
		ft_error(info, "fork failed", 4);
	if (pid == 0) //child proccess
	{
		if (ft_strncmp(info->in_cmd[0], "./", 2) == 0)
			child_aux = ft_file_taster(info, info->in_cmd[0]);
		if (child_aux == 3 || child_aux == 2)
			exit (child_aux);
		else 
			child_aux = ft_aux_taster(info, child_aux, pid, info->in_cmd);
		if (child_aux == 3)
			exit (child_aux);
		else
			exit (child_aux);
	}
	else // parent proccess
	{
		int exit_status = 0;
		child_aux = waitpid(0, &cmp_aux, 0);
		if (WIFEXITED(cmp_aux)) 
			exit_status = WEXITSTATUS(cmp_aux);
		printf("exit_status ->%i\n", exit_status);
		if (exit_status == 3)
			child_aux = ft_aux_taster(info, 0, 0, info->in_cmd);
		if (child_aux == 1)
			return (cmp_aux);
		if (ft_strncmp(info->out_cmd[0], "./", 2) == 0)
			cmp_aux = ft_file_taster(info, info->out_cmd[0]);
		if (cmp_aux == 3 && ft_strncmp(info->out_cmd[0], "./", 2) == 0)
			return (cmp_aux);
		else 
			cmp_aux = ft_aux_taster(info, cmp_aux, pid, info->out_cmd);
		if (cmp_aux == 3)
			return (cmp_aux);
		else
			return (cmp_aux);
	}
}

int	ft_file_taster(t_pipe *info, char *cmd)
{
	if ((access(cmd, F_OK | X_OK)) == 0)
		return (3);
	else if ((access(cmd, F_OK )) == 0)
	{
		ft_printf("pipex: permission denied: %s\n", cmd);
		return (2);
		ft_error(info, "no permission", 3);
	}
	else
		return (1);
}

int	ft_aux_taster(t_pipe *info, int aux, int pid, char **cmd)
{
	if (aux == 3)
	{
		if (pid == 0)
			info->in_path = cmd[0];
		else if (pid != 0)
			info->out_path = cmd[0];
		return (3);
	}
	else
	{
		if (pid == 0)
			info->in_path = ft_check_path(info, cmd);
		else
			info->out_path = ft_check_path(info, cmd);
		if (ft_check_path(info, cmd) == NULL)
			return (1);
		else
			return (3);
	}
}
*/
void	ft_free_array(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	while (--i)
		free(res[i]);
	free(res[i]);
	free(res);
}

void	ft_clean(t_pipe *info)
{
	if (info->f_fd != -1)
		close(info->f_fd);
	if (info->l_fd != -1)
		close(info->l_fd);
	if (info->in_cmd != NULL)
		ft_free_array(info->in_cmd);
	if (info->out_cmd != NULL)
		ft_free_array(info->out_cmd);
	if (info->in_path != NULL)
		free(info->in_path);
	if (info->out_path != NULL)
		free(info->out_path);
	if (info->paths != NULL)
		ft_free_array(info->paths);
	exit(EXIT_FAILURE);
}

void	ft_error(t_pipe *info, const char *message, int flag_nb)
{
	if (flag_nb == 2)
	{
		if (access(info->f_file, F_OK))
			ft_printf("pipex: no such file or directory: %s\n", message);
		else
			ft_printf("pipex: permission denied: %s\n", message);
	}
	else if (flag_nb == 4)
		ft_printf("pipex: %s", message);
	else if (flag_nb == 5)
	{
		if (access(info->in_cmd[0], F_OK) != 0)
		{
			if (!info->in_path)
				ft_printf("pipex: command not found: %s\n", info->in_cmd[0]);
		}
		if (access(info->out_cmd[0], F_OK) != 0)
		{
			if (!info->out_path)
				ft_printf("pipex: command not found: %s\n", info->out_cmd[0]);
		}
	}
	ft_clean(info);
}

/*
 * 2 = archivo no encontrado
 * 4 = other errors
 * 5 = both commands
 * */
