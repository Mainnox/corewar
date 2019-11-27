/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:18:20 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/13 18:18:58 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char const *str, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if ((size_t)ft_strlen(str) < n)
	{
		if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (NULL);
	}
	else
	{
		if (!(dest = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
	}
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
