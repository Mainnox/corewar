/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:08:17 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/06/03 19:41:11 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
