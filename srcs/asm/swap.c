/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:30:29 by akremer           #+#    #+#             */
/*   Updated: 2019/12/18 23:09:33 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			swap(unsigned char *a, unsigned char *b)
{
	unsigned char		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void				swap_int(unsigned int *it)
{
	unsigned char 		*p;

	p = (unsigned char *)it;
	swap(p, p + 3);
	swap(p + 1, p + 2);
}