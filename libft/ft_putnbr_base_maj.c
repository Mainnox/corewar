/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:26:12 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/08 21:32:10 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_maj(long nb, unsigned int base)
{
	char *radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
	{
		ft_putnbr_base_maj(nb / base, base);
		ft_putnbr_base_maj(nb % base, base);
	}
	else
		ft_putchar(radix[nb]);
}
