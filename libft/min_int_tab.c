/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:02:37 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/21 21:03:20 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the minimum value of an integer array
*/

int		min_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		min;

	i = 0;
	if (tab == NULL || size == 0)
		return (0);
	min = tab[i];
	while (i < (int)size - 1)
	{
		++i;
		if (min > tab[i])
			min = tab[i];
	}
	return (min);
}
