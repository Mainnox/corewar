/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:41:05 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 04:56:16 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_r_r_r(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;
	char	count;

	count = 1;
	tmp = inst->arg;
	while (tmp)
	{
		if (count == 1)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count == 2)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count == 3)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count > 3)
			error_too_much_arg(handle, i);
		count++;
		tmp = tmp->next;
	}
	if (count != 4)
		error_too_few_arg(handle, i);
}

void		check_d(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;

	tmp = inst->arg;
	if (tmp->type_arg != 4)
		error_wrong_arg(handle, 1, i);
	if (tmp->next)
		error_too_much_arg(handle, i);
}

void		check_di_r(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;
	char	count;

	count = 1;
	tmp = inst->arg;
	while (tmp)
	{
		if (count == 1)
			if (tmp->type_arg != 2 && tmp->type_arg != 4)
				error_wrong_arg(handle, count, i);
		if (count == 2)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count > 2)
			error_too_much_arg(handle, i);
		count++;
		tmp = tmp->next;
	}
	if (count != 3)
		error_too_few_arg(handle, i);
}

void		check_r_ir(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;
	char	count;

	count = 1;
	tmp = inst->arg;
	while (tmp)
	{
		if (count == 1)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count == 2)
			if (tmp->type_arg != 1 && tmp->type_arg != 2)
				error_wrong_arg(handle, count, i);
		if (count > 2)
			error_too_much_arg(handle, i);
		count++;
		tmp = tmp->next;
	}
	if (count != 3)
		error_too_few_arg(handle, i);
}

void		check_rdi_rdi_r(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;
	char	count;

	count = 1;
	tmp = inst->arg;
	while (tmp)
	{
		if (count == 3)
			if (tmp->type_arg != 1)
				error_wrong_arg(handle, count, i);
		if (count > 3)
			error_too_much_arg(handle, i);
		count++;
		tmp = tmp->next;
	}
	if (count != 4)
		error_too_few_arg(handle, i);
}
