/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:12:57 by akremer           #+#    #+#             */
/*   Updated: 2019/12/23 05:26:16 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_name(t_asm *handle, char *buf, t_inst *new)
{
	int			j;
	int			i;

	i = 0;
	j = 0;
	while (ft_isalpha(buf[i]))
		i++;
	while (handle->op_tab[j].name)
	{
		if (ft_strncmp(handle->op_tab[j].name, buf, i) == 0
				&& ft_strlen(handle->op_tab[j].name) == (size_t)i)
		{
			new->name = ft_strndup(buf, i);
			new->opcode = handle->op_tab[j].opcode;
			new->nb_arg = handle->op_tab[j].nb_arg;
			return (i);
		}
		j++;
	}
	return (0);
}

void			put_new_in_handle(t_asm *handle, t_inst *new)
{
	t_inst		*tmp;

	tmp = handle->inst;
	if (!tmp)
		handle->inst = new;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}
