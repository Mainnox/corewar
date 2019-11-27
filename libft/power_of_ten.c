/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:31:48 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/26 18:09:40 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This fuction gives the power of ten the closest to n
** Exemple :	if n = 123,   pow = 100;
**				if n = -1234, pow = 1000;
*/

long		power_of_ten(long n)
{
	long	pow;
	size_t	i;

	i = 0;
	pow = 10;
	n < 0 ? n = -n : 1;
	if (n < 10)
		return (1);
	while (n / pow >= 10)
		pow *= 10;
	return (pow);
}
