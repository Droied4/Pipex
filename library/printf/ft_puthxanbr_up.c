/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxanbr_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:15:20 by deordone          #+#    #+#             */
/*   Updated: 2023/10/14 05:21:00 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxanbr_up(unsigned int nb)
{
	char	*hex_val;
	int		count;

	count = 0;
	hex_val = "0123456789ABCDEF";
	if (nb > 15)
	{
		count = ft_puthxanbr_up(nb / 16);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(hex_val[nb % 16]) == -1)
		return (-1);
	count++;
	return (count);
}
