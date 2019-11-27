/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:51:40 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/05 15:24:42 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		howmany_num(int n, unsigned int base)
{
	int			i;

	i = 1;
	if (base < 2 || base > 16)
		return (0);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > (int)base - 1)
	{
		n = n / (int)base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int n, unsigned int base)
{
	char		*itoa;
	char		*radix;
	int			pow;
	long		nb;

	nb = n;
	radix = "0123456789abcdef";
	pow = howmany_num(n, base);
	if (!(itoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	itoa[pow--] = '\0';
	if (nb < 0 && base < 10)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		*itoa = '0';
	while (nb > 0)
	{
		itoa[pow--] = radix[(nb % base)];
		nb = nb / base;
	}
	return (itoa);
}
