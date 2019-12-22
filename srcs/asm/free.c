/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 23:50:17 by akremer           #+#    #+#             */
/*   Updated: 2019/12/22 13:29:57 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_arg(t_arg *arg)
{
	t_arg		*tmp;
	t_arg		*tmp2;

	tmp = arg;
	while (tmp)
	{
		if (tmp->label)
			ft_strdel(&tmp->label);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
		tmp2 = NULL;
	}
}

static void		free_inst(t_asm *handle)
{
	t_inst		*tmp;
	t_inst		*tmp2;

	tmp = handle->inst;
	while (tmp)
	{
		if (tmp->label)
			ft_strdel(&tmp->label);
		if (tmp->name)
			ft_strdel(&tmp->name);
		if (tmp->arg)
			free_arg(tmp->arg);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void			free_all(t_asm *handle)
{
	if (handle->bin)
		ft_strdel(&handle->bin);
	if (handle->inst)
		free_inst(handle);
	if (handle->fd_write)
		close(handle->fd_read);
	if (handle->fd_write)
		close(handle->fd_write);
}
