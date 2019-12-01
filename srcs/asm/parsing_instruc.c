/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:45:45 by akremer           #+#    #+#             */
/*   Updated: 2019/12/01 19:02:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					parse_instruc(t_asm *handle, char *buf)
{
	char		**split;

	split = ft_strsplit(buf, SEPARATOR_CHAR);
	ft_printf("ATTENTION LA VERITE: %x\n", -5);
	if (handle)
		ft_printf("buf = %s\n", buf);
	ft_freesplit(split);
	return (0);
}
