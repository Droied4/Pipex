/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:31:42 by deordone          #+#    #+#             */
/*   Updated: 2024/01/15 17:00:25 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_putunsnbr(nb / 10);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
