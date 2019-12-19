/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:59:38 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 05:01:06 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			fill_ocp_0(t_inst *inst, t_arg *arg)
{
	if (arg->type_arg == 1)
		inst->ocp += 64;
	else if (arg->type_arg == 2)
		inst->ocp += 64 + 128;
	else if (arg->type_arg == 4)
		inst->ocp += 128;
}

void			fill_ocp_1(t_inst *inst, t_arg *arg)
{
	if (arg->type_arg == 1)
		inst->ocp += 16;
	else if (arg->type_arg == 2)
		inst->ocp += 16 + 32;
	else if (arg->type_arg == 4)
		inst->ocp += 32;
}

void			fill_ocp_2(t_inst *inst, t_arg *arg)
{
	if (arg->type_arg == 1)
		inst->ocp += 4;
	else if (arg->type_arg == 2)
		inst->ocp += 4 + 8;
	else if (arg->type_arg == 4)
		inst->ocp += 8;
}
