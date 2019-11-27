/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:27:42 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/26 18:06:38 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** il y a encore un pb pour le long min
*/

static unsigned int	neg(long *n, char **ltoa, unsigned int i)
{
	*ltoa[0] = '-';
	*n = -(*n);
	return (i + 1);
}

char				*ltoa(long n)
{
	unsigned int	i;
	unsigned int	digit;
	long			pow;
	char			*ltoa;

	i = 0;
	pow = power_of_ten(n);
	digit = number_of_digit(n);
	if (!(ltoa = (char *)malloc(4 * digit + 1)))
		return (NULL);
	n < 0 ? (i = neg(&n, &ltoa, i)) : 1;
	while (n > 0 || digit--)
	{
		if (pow != 0)
		{
			ltoa[i++] = n / pow + '0';
			n = n - ((n / pow) * pow);
		}
		pow /= 10;
	}
	ltoa[i] = '\0';
	return (ltoa);
}
