/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:11:40 by akremer           #+#    #+#             */
/*   Updated: 2019/12/23 05:29:37 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_label(char *buf, t_inst *new)
{
	int			i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, buf[i]))
		i++;
	if (buf[i] == LABEL_CHAR)
	{
		new->label = ft_strndup(buf, i);
		return (i + 1);
	}
	return (0);
}

void			put_arg_in_new(t_inst *new, t_arg *arg)
{
	t_arg		*tmp;

	tmp = new->arg;
	if (!tmp)
	{
		new->arg = arg;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = arg;
}

void			add_arg_helper_1(t_asm *handle,
		t_inst *new, char *buf, t_arg *arg)
{
	if ((ft_strcmp(new->name, "sti") == 0
				|| ft_strcmp(new->name, "ldi") == 0
				|| ft_strcmp(new->name, "lldi") == 0
				|| ft_strcmp(new->name, "fork") == 0
				|| ft_strcmp(new->name, "lfork") == 0
				|| ft_strcmp(new->name, "zjmp") == 0))
		arg->valeur = (unsigned short)ft_atoui(buf);
	else
		arg->valeur = ft_atoui(buf);
	if (arg->valeur == 0)
	{
		if (*buf == '-' || *buf == '+')
			buf++;
		if (*buf < '0' || *buf > '9')
			error_instruc(handle, buf);
	}
}

void			add_arg_helper_3(char *buf,
		t_arg *arg, int *j, int i)
{
	buf++;
	*j = *j + 1;
	while (ft_strchr(LABEL_CHARS, buf[i]))
		i++;
	arg->label = ft_strndup(buf, i);
	*j = *j + i;
}

void			add_arg_helper_2(t_asm *handle,
		char *buf, t_arg *arg, int *j)
{
	buf++;
	*j = *j + 1;
	arg->valeur = ft_atoui(buf);
	if (arg->valeur == 0 || arg->valeur > REG_NUMBER)
		error_instruc(handle, buf);
}
