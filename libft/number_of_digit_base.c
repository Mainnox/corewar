/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_digit_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:25:13 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/27 11:45:33 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gives the number of digit of the number
** Exemple :	n = 10,  i = 2;
**				n = -10, i = 3;
**				n = 0;   i = 1;
*/

size_t	number_of_digit_base(long n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= base)
	{
		n = n / base;
		++i;
	}
	return (i + 1);
}
