/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:14:38 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/21 21:02:03 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the maximum value of an integer array
*/

int		max_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		max;

	i = 0;
	if (tab == NULL || size == 0)
		return (0);
	max = tab[i];
	while (i < (int)size - 1)
	{
		++i;
		if (max < tab[i])
			max = tab[i];
	}
	return (max);
}
