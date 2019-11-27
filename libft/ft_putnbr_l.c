/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:09:37 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/08 21:33:28 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		limit_long(long n)
{
	ft_putstr("-9");
	n = n % 1000000000000000000;
	return (n);
}

void			ft_putnbr_l(long n)
{
	if (n == (long)-9223372036854775808ULL)
		n = -limit_long(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr_l(n / 10);
		ft_putnbr_l(n % 10);
	}
}
