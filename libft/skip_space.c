/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:11:40 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/27 01:48:59 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		skip_space(char *str, int i)
{
	if (str[i])
		while (str[i] == ' ' || str[i] == '\t')
			++i;
	else
		return (-1);
	return (i);
}
