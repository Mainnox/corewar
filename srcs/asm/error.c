/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:17:58 by akremer           #+#    #+#             */
/*   Updated: 2019/12/22 21:34:45 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error_ac(t_asm *handle)
{
	ft_printf("Wrong number of arguments !\n%s\nI'm not polygamous !\n", USAGE);
	free_all(handle);
	exit(0);
}

void		error_open(t_asm *handle)
{
	ft_printf("Open failed !\nCheck the path of your .s file.\n%s\n", USAGE);
	free_all(handle);
	exit(0);
}

void		error_name(t_asm *handle)
{
	ft_printf("Wrong name or name is missing !\n%s\n", USAGE);
	free_all(handle);
	exit(0);
}

void		error_comment(t_asm *handle)
{
	ft_printf("Wrong comment !\n%s\n", USAGE);
	free_all(handle);
	exit(0);
}

void		error_malloc(t_asm *handle)
{
	ft_printf("Say whaaaaaaaaaaaaaaaaaaaaat !\nWhat is wrong with you !");
	ft_printf("Gentleman aren't break mallloc for no reason that's hurt !");
	free_all(handle);
	exit(0);
}
