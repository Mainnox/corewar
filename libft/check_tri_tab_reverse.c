/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tri_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:52:26 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/04/11 19:15:46 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decroissant(int *tab, int size)
{
	int		i;

	i = 0;
	if (size >= 2)
	{
		while (i < size - 1)
		{
			if (tab[i] < tab[i + 1])
				return (0);
			++i;
		}
	}
	return (1);
}

int			check_tri_tab_reverse(int *tab, int size)
{
	int		i;
	int		pos;

	i = 0;
	if (size == 0)
		return (0);
	pos = pos_max_int_tab(tab, size);
	if (decroissant(tab, pos) == 0 || decroissant(&tab[pos], size - pos) == 0)
		return (0);
	if (pos != 0 && tab[size - 1] < tab[0])
		return (0);
	return (1);
}
