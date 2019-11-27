/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:51:40 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/12/26 18:09:49 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		howmany_num(int n)
{
	int			i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*itoa;
	int			pow;
	long		nb;

	nb = n;
	pow = howmany_num(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	itoa[pow--] = '\0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		*itoa = '0';
	while (nb > 0)
	{
		itoa[pow--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (itoa);
}
