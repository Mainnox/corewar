/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:36:06 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/12 20:36:21 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, void const *src, size_t len)
{
	unsigned char	*src_uc;
	unsigned char	*dest_uc;
	size_t			i;

	i = 0;
	src_uc = (unsigned char *)src;
	dest_uc = (unsigned char *)dest;
	if (src_uc >= dest_uc)
	{
		while (i < len)
		{
			dest_uc[i] = src_uc[i];
			i++;
		}
	}
	while (i < len)
	{
		dest_uc[len - 1 - i] = src_uc[len - 1 - i];
		i++;
	}
	return (dest);
}
