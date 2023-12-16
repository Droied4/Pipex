/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extractor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:31:30 by deordone          #+#    #+#             */
/*   Updated: 2023/12/16 13:10:52 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_ffile2fd(char **argv)
{
	char *infile;
	int	size;
	int fd;

	if (argv[1][0])
	{
		size = ft_strlen(argv[1]);
		infile = malloc(sizeof(char) * size + 1);
		if (!infile)
			return (-1);
		ft_strlcpy(infile, argv[1], size);
	}
	else 
		return (-1);
	fd = open(infile, O_RDONLY | O_CREAT);
	return (fd);
}

int	ft_lfile2fd(char **argv);
