/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmeno <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:10:22 by carmeno           #+#    #+#             */
/*   Updated: 2023/12/13 03:43:12 by carmeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv)
{
	if (argc <= 3)
	{
		errno = 1;
		perror("Too few arguments");
		return (errno);
	}
	if (argv[0][1])
		printf("hola mundo\n");
	perror("todo ok");
	return (0);
}
