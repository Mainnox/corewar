/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:25:12 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/08 21:31:44 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		limit_long(long nb)
{
	ft_putstr("-9");
	nb = nb % 1000000000000000000;
	return (nb);
}

void			ft_putnbr_base(long nb, unsigned int base)
{
	char	*radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789abcdef";
	if (nb == LONG_MIN)
		nb = -limit_long(nb);
	if (nb < 0 && base == 10)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= (long)base)
	{
		ft_putnbr_base(nb / (long)base, base);
		ft_putnbr_base(nb % (long)base, base);
	}
	else
		ft_putchar(radix[nb]);
}
