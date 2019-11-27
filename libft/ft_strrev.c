/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:49:11 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/12 20:17:30 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *rev)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(rev) - 1;
	while (i < j)
	{
		tmp = rev[i];
		rev[i++] = rev[j];
		rev[j--] = tmp;
	}
	return (rev);
}
