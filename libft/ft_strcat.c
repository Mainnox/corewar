/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:31:45 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/06/03 21:37:24 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	int		i;
	int		len_d;

	i = 0;
	len_d = ft_strlen(dest);
	if (src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i + len_d] = src[i];
		++i;
	}
	dest[i + len_d] = '\0';
	return (dest);
}
