/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:55:41 by deordone          #+#    #+#             */
/*   Updated: 2023/11/07 17:31:49 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isintmin(int count)
{
	if (write(1, "-2", 2) == -1)
		return (-1);
	ft_putstr("147483648");
	return (11 + count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (ft_isintmin(count));
	if (nb < 0)
	{
		count += ft_putchar('-');
		if (count == -1)
			return (-1);
		nb *= -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
