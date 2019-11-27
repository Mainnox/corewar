/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:34:10 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/01/08 12:47:15 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char *str;

	if (size == 0)
	{
		str = ft_strdup((char *)ptr);
		free(ptr);
		return ((void *)str);
	}
	if (!(ptr = malloc(size)))
		if (!(str = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	return (NULL);
}
