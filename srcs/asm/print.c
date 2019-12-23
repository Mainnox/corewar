/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:16 by akremer           #+#    #+#             */
/*   Updated: 2019/12/23 06:04:25 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_inst_helper(t_asm *handle, t_arg *arg, t_inst *inst)
{
	if (arg->type_arg == 1)
		write(handle->fd_write, &arg->valeur, 1);
	else if (arg->type_arg == 2 || (arg->type_arg == 4
				&& (ft_strcmp(inst->name, "sti") == 0
					|| ft_strcmp(inst->name, "ldi") == 0
					|| ft_strcmp(inst->name, "lldi") == 0
					|| ft_strcmp(inst->name, "fork") == 0
					|| ft_strcmp(inst->name, "lfork") == 0
					|| ft_strcmp(inst->name, "zjmp") == 0)))
	{
		swap_short((unsigned short *)&arg->valeur);
		write(handle->fd_write, &arg->valeur, sizeof(unsigned short));
	}
	else if (arg->type_arg == 4)
	{
		swap_int(&arg->valeur);
		write(handle->fd_write, &arg->valeur, sizeof(unsigned int));
	}
}

static void		print_inst(t_asm *handle)
{
	t_inst		*inst;
	t_arg		*arg;

	inst = handle->inst;
	while (inst)
	{
		arg = inst->arg;
		write(handle->fd_write, &inst->opcode, 1);
		if (ft_strcmp(inst->name, "live") != 0
				&& ft_strcmp(inst->name, "fork") != 0
				&& ft_strcmp(inst->name, "lfork") != 0
				&& ft_strcmp(inst->name, "zjmp") != 0)
			write(handle->fd_write, &inst->ocp, 1);
		while (arg)
		{
			print_inst_helper(handle, arg, inst);
			arg = arg->next;
		}
		inst = inst->next;
	}
}

static void		print_header(t_asm *handle)
{
	swap_int(&handle->header.magic);
	swap_int(&handle->header.prog_size);
	write(handle->fd_write, &handle->header, sizeof(handle->header));
}

void			print_cor(t_asm *handle)
{
	char		zero;
	char		tmp;
	char		i;

	i = 0;
	zero = 0;
	tmp = handle->size_magic;
	handle->fd_write = open(handle->bin, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRWXU | S_IRWXG | S_IRWXO);
	if (handle->fd_write == -1)
		error_open(handle);
	print_header(handle);
	print_inst(handle);
}
