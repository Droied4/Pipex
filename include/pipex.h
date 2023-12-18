/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:08:12 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/18 16:05:44 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
	int		f_fd;
	int		l_fd;
	char	*path;
	char	**in_cmd;
	char	**out_cmd;
}			t_pipe;

/* ╔═══════════════════════════════════════════════════════╗
 * 		 	 ❖ ❖ ❖  MAIN  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/

void		ft_print_info(t_pipe *info);
void		ft_extractor(int argc, char **argv, t_pipe *info);
/* ╔═══════════════════════════════════════════════════════╗
 * 			 ❖ ❖ ❖  UTILS  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/
void		ft_init_info(t_pipe *info);

/* ╔═══════════════════════════════════════════════════════╗
 * 	                 ❖ ❖ ❖  ERRORS  ❖ ❖ ❖
   ╚═══════════════════════════════════════════════════════╝	*/

#endif
