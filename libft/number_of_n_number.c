/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_n_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:58:01 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/08/17 17:31:14 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	 This function can give you the number of integer in pos characters
**	of a string. If the string is invalid (non numeric character, sign
**	character without number or with space before number) the function return -1
*/

int		number_of_n_number(char *str, int pos)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && i < pos)
	{
		if (((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ') || ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9')))
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			++n;
			while (str[i] >= '0' && str[i] <= '9' && i < pos)
				++i;
		}
		else
			++i;
	}
	return (n);
}
