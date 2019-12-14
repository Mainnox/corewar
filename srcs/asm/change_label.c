/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 02:22:57 by akremer           #+#    #+#             */
/*   Updated: 2019/12/14 01:36:17 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				find_label(t_asm *handle, char *label)
{
	t_inst		*tmp;
	int			i;

	i = 0;
	tmp = handle->inst;
	while (tmp)
	{
		if (tmp->label)
			if (ft_strcmp(tmp->label, label) == 0)
				return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

static void				reverse_label(t_asm *handle, t_arg *ar, int start, int reach)
{
	t_inst		*ins;
	int			i;

	i = 0;
	ins = handle->inst;
	while (ins && i < reach)
	{
		if (i >= start)
			ar->valeur -= ins->size;
		i++;
		ins = ins->next;
	}
}

static void				set_label(t_asm *handle, t_arg *ar, int start, int reach)
{
	t_inst		*ins;
	int			i;

	i = 0;
	ins = handle->inst;
	while (ins && i < reach)
	{
		if (i >= start)
			ar->valeur += ins->size;
		i++;
		ins = ins->next;
	}
}

static void				fill_value(t_asm *handle, t_arg *ar, int where, int here)
{
	int		start;
	int		reach;
	int		i;

	i = 0;
	if (here > where)
	{
		start = where;
		reach = here;
		reverse_label(handle, ar, start, reach);
	}
	else
	{
		start = here;
		reach = where;
		set_label(handle, ar, start, reach);
	}
}

void					change_label(t_asm *handle)
{
	t_inst		*ins;
	t_arg		*ar;
	int			here;

	here = 0;
	ins = handle->inst;
	while (ins)
	{
		ar = ins->arg;
		while (ar)
		{
			if (ar->label)
				fill_value(handle, ar, find_label(handle, ar->label), here);
			ar = ar->next;
		}
		here++;
		ins = ins->next;
	}
}
