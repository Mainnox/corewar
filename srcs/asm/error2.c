/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:30:23 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 04:31:51 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error_too_few_arg(t_asm *handle, int i)
{
	ft_printf("Too few argument for the inst number %d !\nHmmmm my ", i);
	ft_printf("ex-gf told me that often ...\nTHANKS YOU I'M SAD NOW !\n");
	free_all(handle);
	exit(0);
}

void		error_too_much_arg(t_asm *handle, int nb_inst)
{
	ft_printf("Too much arg for the inst number %d !\n", nb_inst);
	ft_printf("Go tell him it's not a moulin here !\n");
	free_all(handle);
	exit(0);
}

void		error_wrong_arg(t_asm *handle, char nb_arg, int nb_inst)
{
	ft_printf("The argument %d of the instruction %d got ", nb_arg, nb_inst);
	ft_printf("nothing to do here !\nIt's like bred a incest child that's ");
	ft_printf("gonna be ...\nHmmm ...\nLet's say rather dysfunctional.\n");
	free_all(handle);
	exit(0);
}

void		error_no_inst(t_asm *handle)
{
	ft_printf("No instruction for your champ !\nCannot create ");
	ft_printf("empty thing !\nI\'m not Nabilla's father !\n");
	free_all(handle);
	exit(0);
}

void		error_instruc(t_asm *handle, char *buf)
{
	ft_printf("Unknow command or params line %d ", handle->count_line);
	ft_printf(": \"%s\"\n", buf);
	ft_printf("If I know what I'm unknowing that's mean ...\nSEGFAULT !\n");
	free_all(handle);
	exit(0);
}
