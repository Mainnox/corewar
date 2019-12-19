/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:46:08 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 04:48:01 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_r_rdi_dr(t_asm *handle, t_inst *inst, int i)
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
		if (count == 3)
			if (tmp->type_arg != 1 && tmp->type_arg != 4)
				error_wrong_arg(handle, count, i);
		if (count > 3)
			error_too_much_arg(handle, i);
		count++;
		tmp = tmp->next;
	}
	if (count != 4)
		error_too_few_arg(handle, i);
}

void		check_rdi_rd_r(t_asm *handle, t_inst *inst, int i)
{
	t_arg	*tmp;
	char	count;

	count = 1;
	tmp = inst->arg;
	while (tmp)
	{
		if (count == 2)
			if (tmp->type_arg != 1 && tmp->type_arg != 4)
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
