/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:26:03 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/01/05 15:47:49 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putstrsub(char const *s, int start, size_t len)
{
	if (s[start])
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		write(1, s + start, len);
	}
}
