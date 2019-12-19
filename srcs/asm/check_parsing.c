/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:42:37 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 04:56:18 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_r(t_asm *handle, t_inst *inst, int i)
{
	t_arg *tmp;

	tmp = inst->arg;
	if (tmp->type_arg != 1)
		error_wrong_arg(handle, 1, i);
	if (tmp->next)
		error_too_much_arg(handle, i);
}

static void		check_inst_helper(t_asm *handle, t_inst *tmp, int i)
{
	if (ft_strcmp(tmp->name, "live") == 0
			|| ft_strcmp(tmp->name, "fork") == 0
			|| ft_strcmp(tmp->name, "zjmp") == 0
			|| ft_strcmp(tmp->name, "lfork") == 0)
		check_d(handle, tmp, i);
	if (ft_strcmp(tmp->name, "ld") == 0
			|| ft_strcmp(tmp->name, "lld") == 0)
		check_di_r(handle, tmp, i);
	if (ft_strcmp(tmp->name, "add") == 0
			|| ft_strcmp(tmp->name, "sub") == 0)
		check_r_r_r(handle, tmp, i);
	if (ft_strcmp(tmp->name, "st") == 0)
		check_r_ir(handle, tmp, i);
	if (ft_strcmp(tmp->name, "and") == 0
			|| ft_strcmp(tmp->name, "or") == 0
			|| ft_strcmp(tmp->name, "xor") == 0)
		check_rdi_rdi_r(handle, tmp, i);
	if (ft_strcmp(tmp->name, "ldi") == 0
			|| ft_strcmp(tmp->name, "lldi") == 0)
		check_rdi_rd_r(handle, tmp, i);
	if (ft_strcmp(tmp->name, "sti") == 0)
		check_r_rdi_dr(handle, tmp, i);
	if (ft_strcmp(tmp->name, "aff") == 0)
		check_r(handle, tmp, i);
}

static void		check_inst(t_asm *handle)
{
	t_inst		*tmp;
	int			i;

	i = 0;
	tmp = handle->inst;
	while (tmp)
	{
		i++;
		check_inst_helper(handle, tmp, i);
		tmp = tmp->next;
	}
}

int				check_blanc(char *buf)
{
	if (buf[0] == '\0')
		return (1);
	while (*buf)
	{
		if (*buf == COMMENT_CHAR)
			return (1);
		if (*buf != ' ' && *buf != '\t' && *buf != '\r')
			return (0);
		buf++;
	}
	return (1);
}

void			check_parsing(t_asm *handle)
{
	if (handle->header.prog_name[0] == '\n')
		error_name(handle);
	if (handle->header.comment[0] == '\n')
		error_comment(handle);
	if (handle->inst)
		check_inst(handle);
	else
		error_no_inst(handle);
}
