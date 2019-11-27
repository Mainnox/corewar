/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:19:14 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/07 06:31:33 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gives the number of digit of the number
** Exemple :	n = 10,  i = 2;
**				n = -10, i = 3;
**				n = 0;   i = 1;
*/

size_t		number_of_digit(long n)
{
	size_t i;

	i = 0;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		++i;
	}
	return (i + 1);
}
