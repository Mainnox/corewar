/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:43:45 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/08/17 17:31:04 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	 This function can give you the number of integer in a string
**	If the string is invalid (non numeric character, sign character without
**	number or with space before number) the function return -1
*/

int		number_of_number(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ') || ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9')))
			return (-1);
		if (str[i] >= '0' && str[i] <= '9')
		{
			++n;
			while (str[i] >= '0' && str[i] <= '9')
				++i;
		}
		else
			++i;
	}
	return (n);
}
