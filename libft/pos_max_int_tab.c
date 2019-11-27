/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_max_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:34:50 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/25 20:38:26 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the index of the maximum value of an integer array
*/

int		pos_max_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		pos;
	int		max;

	i = 1;
	pos = 0;
	if (tab == NULL || size == 0)
		return (-1);
	max = tab[i - 1];
	while (i < (int)size)
	{
		if (max < tab[i])
		{
			max = tab[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}
