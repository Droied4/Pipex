/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxhaptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 01:03:55 by deordone          #+#    #+#             */
/*   Updated: 2023/10/14 05:25:14 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxaptr(unsigned long nb)
{
	char	*pointer_val;
	int		count;

	count = 0;
	pointer_val = "0123456789abcdef";
	if (!nb)
		return (ft_putchar('0'));
	if (nb > 15)
	{
		count = ft_puthxaptr(nb / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(pointer_val[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
