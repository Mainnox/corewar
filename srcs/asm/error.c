/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:17:58 by akremer           #+#    #+#             */
/*   Updated: 2019/11/27 03:37:20 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void		error_ac(void)
{
	ft_printf("wrong number of arguments !\n%s\n", USAGE);
	exit(0);
}

void		error_open(void)
{
	ft_printf("open failed !\ncheck your .s file.\n%s\n", USAGE);
	exit(0);
}

void		error_name(void)
{
	ft_printf("wrong name !\n%s\n", USAGE);
	exit(0);
}

void		error_comment(void)
{
	ft_printf("wrong comment !\n%s\n", USAGE);
	exit(0);
}
