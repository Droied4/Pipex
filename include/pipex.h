/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:08:12 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/18 13:45:01 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_pipe
{
	int	f_fd;
	int	l_fd;
	char	*path;
	char	**argv;
	char	**env;
} t_pipe;

/* ╔═══════════════════════════════════════════════════════╗
 * 		  			 ❖ ❖ ❖  MAIN  ❖ ❖ ❖ 
   ╚═══════════════════════════════════════════════════════╝	*/

/* ╔═══════════════════════════════════════════════════════╗
 * 		  		    ❖ ❖ ❖  EXTRACTOR  ❖ ❖ ❖ 
   ╚═══════════════════════════════════════════════════════╝	*/

int	ft_ffile2fd(char **argv);
int	ft_lfile2fd(int argc, char **argv);

#endif
