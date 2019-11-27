/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:09:16 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/09 18:11:13 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	if (!s2[i])
		return ((char *)s1);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j])
		{
			if (!s2[j + 1])
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
