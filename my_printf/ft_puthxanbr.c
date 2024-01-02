/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxanbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:31:09 by deordone          #+#    #+#             */
/*   Updated: 2023/11/07 16:44:01 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxanbr(unsigned int nb)
{
	char	*hex_val;
	int		count;

	count = 0;
	hex_val = "0123456789abcdef";
	if (nb > 15)
	{
		count = ft_puthxanbr(nb / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(hex_val[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
