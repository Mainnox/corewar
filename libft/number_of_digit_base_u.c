/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_digit_base_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:40:06 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/02/22 14:50:43 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gives the number of digit of the number
** Exemple :	n = 10,  i = 2;
**				n = -10, i = 3;
**				n = 0;   i = 1;
*/

size_t		number_of_digit_base_u(unsigned long n, unsigned int base)
{
	size_t i;

	i = 0;
	while (n >= base)
	{
		n = n / base;
		++i;
	}
	return (i + 1);
}
