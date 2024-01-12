/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:04:21 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/12 18:20:36 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int     ft_file_taster(char *cmd)
{
        if ((access(cmd, F_OK | X_OK)) == 0)
                return (3);
        else if ((access(cmd, F_OK )) == 0)
        {
                ft_printf("pipex: permission denied: %s\n", cmd);
                return (2);
        }
        else
                return (1);
}

static int     ft_aux_taster(t_pipe *info, int aux, int pid, char **cmd)
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

int     ft_handle_access(t_pipe *info)
{
        int     pid;
        int     child_aux;
        int cmp_aux;

        cmp_aux = 0;
        child_aux = 0;
        pid = fork();
        if (pid == -1)
                ft_error(info, "fork failed", 4);
        if (pid == 0) //child proccess
        {
                if (ft_strncmp(info->in_cmd[0], "./", 2) == 0)
                        child_aux = ft_file_taster(info->in_cmd[0]);
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
                        cmp_aux = ft_file_taster(info->out_cmd[0]);
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
