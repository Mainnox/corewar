/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:57:43 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/08 21:35:05 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** to get adress of a variable
*/

void	ft_put_address(unsigned long nb, unsigned int base, int i)
{
	char			*radix;

	radix = "0123456789abcdef";
	if (base != 16)
		return ;
	if (i == 1)
		ft_putstr("0x");
	if (nb >= base)
	{
		ft_put_address(nb / base, base, 0);
		ft_put_address(nb % base, base, 0);
	}
	else
		ft_putchar(radix[nb]);
}
