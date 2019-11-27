/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:25:20 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/06/05 23:08:52 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (str)
	{
		if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (NULL);
		while (str[i])
		{
			dest[i] = str[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (dest);
}
