/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:09:28 by deordone          #+#    #+#             */
/*   Updated: 2023/10/14 05:10:46 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(const char *str);
int		ft_putnbr(int nb);
int		ft_putunsnbr(unsigned int nb);
int		ft_puthxanbr(unsigned int n);
int		ft_puthxanbr_up(unsigned int n);
int		ft_puthxaptr(unsigned long n);

#endif
