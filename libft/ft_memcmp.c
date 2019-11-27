/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:36:57 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/14 21:56:33 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *dest, void const *src, size_t n)
{
	unsigned char const *d;
	unsigned char const *s;

	d = dest;
	s = src;
	if (dest == src || n == 0)
		return (0);
	while (n > 0)
	{
		if (*d != *s)
			return (*d - *s);
		n--;
		d++;
		s++;
	}
	return (0);
}
