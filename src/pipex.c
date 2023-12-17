/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:29:46 by deordone          #+#    #+#             */
/*   Updated: 2023/12/17 14:59:03 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{
	int fd1;
	int fd2;

	if (argc < 5)
		exit(1);
	fd1 = ft_ffile2fd(argv);
	printf("%d\n", fd1);
	close(fd1);
	fd2 = ft_lfile2fd(argc, argv);
	printf("%d\n", fd2);
	close(fd2);
	return (0);
}
