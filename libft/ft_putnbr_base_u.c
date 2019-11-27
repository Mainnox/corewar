/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:31:57 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/08 21:32:26 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base_u(unsigned long nb, unsigned int base)
{
	char	*radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789abcdef";
	if (nb >= (unsigned long)base)
	{
		ft_putnbr_base(nb / (unsigned long)base, base);
		ft_putnbr_base(nb % (unsigned long)base, base);
	}
	else
		ft_putchar(radix[nb]);
}
