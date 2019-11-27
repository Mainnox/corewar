/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_min_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:21 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/25 20:38:57 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the index of the minimum value of an integer array
*/

int		pos_min_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		pos;
	int		min;

	i = 1;
	pos = 0;
	if (tab == NULL || size == 0)
		return (-1);
	min = tab[i - 1];
	while (i < (int)size)
	{
		if (min > tab[i])
		{
			min = tab[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}
