/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:08:12 by carmeno           #+#    #+#             */
/*   Updated: 2024/01/03 14:02:10 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../my_printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	int		f_fd;
	int		l_fd;
	char	*f_file;
	char	*l_file;
	char	*in_path;
	char	*out_path;
	char	**in_cmd;
	char	**out_cmd;
	char	**paths;
}			t_pipe;

/* ╔═══════════════════════════════════════════════════════╗
 * 				 ❖ ❖ ❖  MAIN  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/

void		ft_print_info(t_pipe *info);
void		ft_init_info(t_pipe *info, char **argv, int argc);
void		ft_extractor(char **argv, t_pipe *info, char *envp[]);
void		ft_parse_vortex(int argc, char **argv, t_pipe *info, char *envp[]);

/* ╔═══════════════════════════════════════════════════════╗
 * 				❖ ❖ ❖  UTILS  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/

void		ft_vortex(t_pipe *info);
char		*ft_check_path(t_pipe *info, char **arg_cmd, int i);

/* ╔═══════════════════════════════════════════════════════╗
 * 		              ❖ ❖ ❖  ERRORS  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/

void		ft_error(t_pipe *info, const char *message, int flag_nb);
void		ft_clean(t_pipe *info);
void		ft_free_array(char **res);

#endif
