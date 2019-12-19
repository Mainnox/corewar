/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:47:47 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 03:03:27 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			test_handle(t_asm *handle)
{
	int		i;

	i = 0;
	ft_printf("\n*================================================================================*\n");
	ft_printf("|                                     Handle_asm                                 |\n");
	ft_printf("*================================================================================*\n");
	ft_printf("|                                                                                |\n");
	ft_printf("| handle->fd_read =       %10d      handle->fd_write =        %10d   |\n", handle->fd_read, handle->fd_write);
	ft_printf("|                                                                                |\n");
	ft_printf("| handle->av      =      %35s                     |\n", handle->av);
	ft_printf("| handle->bin     =      %35s                     |\n", handle->bin);
	ft_printf("\n*================================================================================*\n");
	ft_printf("|                                     Header_asm                                 |\n");
	ft_printf("*================================================================================*\n");
	ft_printf("|                                                                                |\n");
	ft_printf("| header.prog_name=      %35s                     |\n", handle->header.prog_name);
	ft_printf("| header.comment  =      %35s                     |\n", handle->header.comment);
	ft_printf("| header.prog_size=      %35#x                     |\n", handle->header.prog_size);
	ft_printf("|                                                                                |\n");
	ft_printf("*================================================================================*\n");
}

void				test_inst(t_asm *handle)
{
	t_inst		*tmp;
	t_arg		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = handle->inst;
	while (tmp)
	{
		ft_printf("*================================================================================*\n");
		ft_printf("|					t_inst list nb %d		         |\n", i);
		ft_printf("*================================================================================*\n");
		ft_printf("|	t_inst nb %d = name = %s\n", i, tmp->name);
		ft_printf("|	t_inst nb %d = opcode = %hhd\n", i, tmp->opcode);
		ft_printf("|	t_inst nb %d = label = %s\n", i, tmp->label);
		ft_printf("|	t_inst nb %d = nb_arg = %hhd\n", i, tmp->nb_arg);
		ft_printf("|	t_inst nb %d = size = %d\n", i, tmp->size);
		ft_printf("|	t_inst nb %d = ocp = %#hhx\n", i, tmp->ocp);
		tmp2 = tmp->arg;
		j = 0;
		while (tmp2)
		{
			ft_printf("|	t_inst nb %d = arg[%d] = type_arg = %hhd\n", i, j, tmp2->type_arg);
			ft_printf("|	t_inst nb %d = arg[%d] = label = %s\n", i, j, tmp2->label);
			if ((ft_strcmp(tmp->name, "sti") == 0
								|| ft_strcmp(tmp->name, "ldi") == 0
								|| ft_strcmp(tmp->name, "lldi") == 0
								|| ft_strcmp(tmp->name, "fork") == 0
								|| ft_strcmp(tmp->name, "lfork") == 0
								|| ft_strcmp(tmp->name, "zjmp") == 0))
				ft_printf("|	t_inst nb %d = arg[%d] = valeur = %#hx\n", i, j, tmp2->valeur);
			else
				ft_printf("|	t_inst nb %d = arg[%d] = valeur = %#x\n", i, j, tmp2->valeur);
			tmp2 = tmp2->next;
			j++;
		}
		ft_printf("*================================================================================*\n");
		i++;
		tmp = tmp->next;
	}
}

void				test_op(t_asm *handle)
{
	int		i;

	i = 0;
	while (handle->op_tab[i].name)
	{
		ft_printf("handle->op_tab[%d].name = %s\n", i, handle->op_tab[i].name);
		ft_printf("handle->op_tab[%d].nb_arg = %d\n", i, handle->op_tab[i].nb_arg);
		ft_printf("handle->op_tab[%d].arg1 = %d\n", i, handle->op_tab[i].args[0]);
		ft_printf("handle->op_tab[%d].arg2 = %d\n", i, handle->op_tab[i].args[1]);
		ft_printf("handle->op_tab[%d].arg3 = %d\n", i, handle->op_tab[i].args[2]);
		ft_printf("handle->op_tab[%d].opcode = %hhd\n", i, handle->op_tab[i].opcode);
		ft_printf("handle->op_tab[%d].cycle = %d\n", i, handle->op_tab[i].cycle);
		ft_printf("handle->op_tab[%d].descrip = %s\n", i, handle->op_tab[i].descrip);
		ft_printf("handle->op_tab[%d].jesaispas = %hhd\n", i, handle->op_tab[i].jesaispas);
		ft_printf("handle->op_tab[%d].luinonplus = %hhd\n", i, handle->op_tab[i].luinonplus);
		i++;
	}
}
