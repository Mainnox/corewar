/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:16 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 04:01:04 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_hex_fd(t_asm *handle, unsigned int nb, char size, char odd)
{
	char				tab[size + 1];
	int					i;
	unsigned int		tmp;

	tmp = 0;
	i = -1;
	ft_bzero(tab, sizeof(tab));
	while (++i < size)
	{
		tab[i] = nb % 16;
		ft_printf("size = %d\n tab[%d] = %hhd\n", size, i, tab[i]);
		nb /= 16;
	}
	ft_strrev(tab);
	ft_printf("Il passe la !\n");
	i = 0;
	if (odd)
		write(handle->fd_write, &tab[i++], 1);
	while (tab[i] && size--)
	{
		tmp = tmp * 16 + tab[i];
		if (tmp >= 16)
		{
			write(handle->fd_write, &tmp, 1);
			tmp = 0;
		}
		i++;
	}
}

/*static void		print_inst(t_asm *handle)
{
	t_inst		*inst;
	t_arg		*arg;
	int			size;
	int			tmp;
	int			test_inst;
	int			test_arg;

	test_arg = 0;
	test_inst = 0;
	size = 0;
	tmp = 0;
	inst = handle->inst;
	while (inst)
	{
		ft_printf("inst->name = %s\n", inst->name);
		if (inst->opcode)
		{
			write(handle->fd_write, &inst->opcode, 1);
			if (ft_strcmp(inst->name, "live") != 0 && ft_strcmp(inst->name, "fork") != 0
					&& ft_strcmp(inst->name, "lfork") != 0
					&& ft_strcmp(inst->name, "zjmp") != 0)
				write(handle->fd_write, &inst->ocp, 1);
			arg = inst->arg;
			while (arg)
			{
				test_arg = 0;
				if (arg->type_arg == 1)
					write(handle->fd_write, &arg->valeur, 1);
				else if (arg->type_arg == 2 || (arg->type_arg == 4
							&& (ft_strcmp(inst->name, "sti") == 0
								|| ft_strcmp(inst->name, "ldi") == 0
								|| ft_strcmp(inst->name, "lldi") == 0
								|| ft_strcmp(inst->name, "fork") == 0
								|| ft_strcmp(inst->name, "lfork") == 0
								|| ft_strcmp(inst->name, "zjmp") == 0)))
				{
					size = ft_nbrlen((unsigned long long)arg->valeur, 0, 16);
					tmp = 2;
					ft_printf("size = %d\n", size);
					while (tmp - size > 0)
					{
						write(handle->fd_write, &handle->zero, 1);
						tmp--;
					}
					print_hex_fd(handle, arg->valeur, size, (size / 2) ? 0 : 1);
				}
				else if (arg->type_arg == 4)
				{
					size = ft_nbrlen((unsigned long long)arg->valeur, 0, 16);
					tmp = 4;
					while (tmp - size > 0)
					{
						write(handle->fd_write, &handle->zero, 1);
						tmp--;
					}
					print_hex_fd(handle, arg->valeur, size, (size / 2) ? 0 : 1);
				}
				ft_printf("test_arg = %d\n", test_arg);
				test_arg++;
				arg = arg->next;
			}
		}
		ft_printf("test_inst = %d\n", test_inst);
		test_inst++;
		inst = inst->next;
	}
}*/

static void		print_inst(t_asm *handle)
{
	t_inst		*inst;
	t_arg		*arg;

	inst = handle->inst;
	while (inst)
	{
		arg = inst->arg;
		write(handle->fd_write, &inst->opcode, 1);
		if (ft_strcmp(inst->name, "live") != 0
				&& ft_strcmp(inst->name, "fork") != 0
				&& ft_strcmp(inst->name, "lfork") != 0
				&& ft_strcmp(inst->name, "zjmp") != 0)
			write(handle->fd_write, &inst->ocp, 1);
		while (arg)
		{
			if (arg->type_arg == 1)
					write(handle->fd_write, &arg->valeur, 1);
			else if (arg->type_arg == 2 || (arg->type_arg == 4
						&& (ft_strcmp(inst->name, "sti") == 0
							|| ft_strcmp(inst->name, "ldi") == 0
							|| ft_strcmp(inst->name, "lldi") == 0
							|| ft_strcmp(inst->name, "fork") == 0
							|| ft_strcmp(inst->name, "lfork") == 0
							|| ft_strcmp(inst->name, "zjmp") == 0)))
			{
				swap_short((unsigned short *)&arg->valeur);
				write(handle->fd_write, &arg->valeur, sizeof(unsigned short));
			}
			else if (arg->type_arg == 4)
			{
				swap_int(&arg->valeur);
				write(handle->fd_write, &arg->valeur, sizeof(unsigned int));
			}
			arg = arg->next;
		}
		inst = inst->next;
	}
}

static void		print_header(t_asm *handle)
{
	swap_int(&handle->header.magic);
	swap_int(&handle->header.prog_size);
	write(handle->fd_write, &handle->header, sizeof(handle->header));
}

void			print_cor(t_asm *handle)
{
	char		zero;
	char		tmp;
	char		i;

	i = 0;
	zero = 0;
	tmp = handle->size_magic;
	handle->fd_write = open(handle->bin, O_CREAT | O_WRONLY | O_TRUNC , S_IRWXU | S_IRWXG | S_IRWXO);
	if (handle->fd_write == -1)
		error_open(handle);
	print_header(handle);
	print_inst(handle);
}

