/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 04:05:52 by akremer           #+#    #+#             */
/*   Updated: 2019/12/03 06:01:06 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			fill_inst_4(t_inst *ins)
{
	t_arg		*arg;

	arg = ins->arg;
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

void				fill_handle(t_asm *handle)
{
	t_inst *tmp;

	tmp = handle->inst;
	while (tmp)
	{
		if (tmp->name)
		{
			if (ft_strcmp(tmp->name, "and") == 0 || ft_strcmp(tmp->name, "live") == 0
					|| ft_strcmp(tmp->name, "ld") == 0 || ft_strcmp(tmp->name, "or") == 0
					|| ft_strcmp(tmp->name, "xor") == 0 || ft_strcmp(tmp->name, "lld") == 0)
				fill_inst_4(tmp);
			else
				fill_inst_2(tmp);
		}
		tmp = tmp->next;
	}
}
