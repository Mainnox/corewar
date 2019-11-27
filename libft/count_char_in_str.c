/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:41:45 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/03/25 21:47:20 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_char_in_str(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c && str)
	{
		while (str[i])
		{
			if (str[i] == c)
				++count;
			++i;
		}
	}
	return (count);
}
