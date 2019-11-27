/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:38:53 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/06/06 19:27:17 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function work like strjoin but
**	if d_s == 0 nothing is freed
**	if d_s == 1, dest is freed
**	if d_s == 2, src is freed
**	if d_s == 3, src and dest is freed,
*/

char		*ft_strjoinfree(char *d, char *s, int d_s)
{
	char	*str;

	str = ft_strjoin(d, s);
	if (str == NULL)
		return (NULL);
	if (d_s == 1 || d_s == 3)
		ft_strdel(&d);
	if (d_s == 2 || d_s == 3)
		ft_strdel(&s);
	return (str);
}
