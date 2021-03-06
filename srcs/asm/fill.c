/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 04:05:52 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 05:02:21 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			fill_inst_4(t_inst *ins)
{
	t_arg		*arg;

	arg = ins->arg;
	if (ft_strcmp(ins->name, "live") == 0 || ft_strcmp(ins->name, "zjmp") == 0
			|| ft_strcmp(ins->name, "fork") == 0
			|| ft_strcmp(ins->name, "lfork") == 0)
		ins->size += 1;
	else
		ins->size += 2;
	while (arg)
	{
		if (arg->type_arg == 1)
			ins->size += 1;
		if (arg->type_arg == 2)
			ins->size += 2;
		if (arg->type_arg == 4)
			ins->size += 4;
		arg = arg->next;
	}
}

static void			fill_inst_2(t_inst *ins)
{
	t_arg		*arg;

	arg = ins->arg;
	if (ft_strcmp(ins->name, "live") == 0 || ft_strcmp(ins->name, "zjmp") == 0
			|| ft_strcmp(ins->name, "fork") == 0
			|| ft_strcmp(ins->name, "lfork") == 0)
		ins->size += 1;
	else
		ins->size += 2;
	while (arg)
	{
		if (arg->type_arg == 1)
			ins->size += 1;
		if (arg->type_arg == 2)
			ins->size += 2;
		if (arg->type_arg == 4)
			ins->size += 2;
		arg = arg->next;
	}
}

/*
**			|  |
**			\__/
*/

static void			fill_ocp(t_inst *inst)
{
	t_arg		*arg;
	int			i;

	i = 0;
	arg = inst->arg;
	while (arg)
	{
		if (i == 0)
			fill_ocp_0(inst, arg);
		else if (i == 1)
			fill_ocp_1(inst, arg);
		else if (i == 2)
			fill_ocp_2(inst, arg);
		i++;
		arg = arg->next;
	}
}

static void			fill_prog_size(t_asm *handle)
{
	t_inst *tmp;

	tmp = handle->inst;
	while (tmp)
	{
		handle->header.prog_size += tmp->size;
		tmp = tmp->next;
	}
}

void				fill_handle(t_asm *handle)
{
	t_inst *tmp;

	tmp = handle->inst;
	while (tmp)
	{
		if (tmp->name)
		{
			fill_ocp(tmp);
			if (ft_strcmp(tmp->name, "and") == 0
					|| ft_strcmp(tmp->name, "live") == 0
					|| ft_strcmp(tmp->name, "ld") == 0
					|| ft_strcmp(tmp->name, "or") == 0
					|| ft_strcmp(tmp->name, "xor") == 0
					|| ft_strcmp(tmp->name, "lld") == 0)
				fill_inst_4(tmp);
			else
				fill_inst_2(tmp);
		}
		tmp = tmp->next;
	}
	fill_prog_size(handle);
}
