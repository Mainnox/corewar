/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:17:58 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 00:16:44 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error_too_few_arg(t_asm *handle, int i)
{
	ft_printf("Too few argument for the inst number %d !\nHmmmm my ex-gf told me that often ...\nTHANKS YOU I'M SAD NOW !\n", i);
	free_all(handle);
	exit(0);
}

void		error_too_much_arg(t_asm *handle, int nb_inst)
{
	ft_printf("Too much arg for the inst number %d !\nGo tell him it's not a moulin here!\n", nb_inst);
	free_all(handle);
	exit(0);
}

void		error_wrong_arg(t_asm *handle, char nb_arg, int nb_inst)
{
	ft_printf("The argument %d of the instruction %d got nothing to do here !\nIt's like bred a incest child that's gonna be ...\nHmmm ...\nLet's say rather dysfunctional.\n", nb_arg, nb_inst);
	free_all(handle);
	exit (0);
}

void		error_no_inst(t_asm *handle)
{
	ft_printf("No instruction for your champ !\nCannot create empty thing !\nI\'m not Nabilla's father !\n");
	free_all(handle);
	exit (0);
}

void		error_instruc(t_asm *handle, char *buf)
{
	ft_printf("Unknow command or params line %d : \"%s\"\n%s\n", handle->count_line, buf, USAGE);
	free_all(handle);
	exit(0);
}

void		error_ac(t_asm *handle)
{
	ft_printf("Wrong number of arguments !\n%s\n", USAGE);
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
	ft_printf("Say whaaaaaaaaaaaaaaaaaaaaat t'as casse maloc frere c'est pas bien !\nRefait pas ca stp !\n");
	free_all(handle);
	exit(0);
}
