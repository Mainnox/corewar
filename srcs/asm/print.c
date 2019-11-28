/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:16 by akremer           #+#    #+#             */
/*   Updated: 2019/11/28 17:45:41 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_magic(t_asm *handle)
{
	char				magic[handle->size_magic + 1];
	int					i;
	unsigned int		tmp;

	tmp = 0;
	i = -1;
	ft_bzero(magic, sizeof(magic));
	while (++i < handle->size_magic)
	{
		magic[i] = handle->header.magic % 16;
		handle->header.magic /= 16;
	}
	ft_strrev(magic);
	i = 0;
	while (i < handle->size_magic)
	{
		ft_printf("magic[%d] = %hhx\n", i, magic[i]);
		i++;
	}
	i = 0;
	if (handle->odd)
		write(handle->fd_write, &magic[i], 1);
	while (magic[i])
	{
		tmp = tmp * 16 + magic[i];
		ft_printf("tmp a i = %d = %x\n", i, tmp);
		if (tmp >= 16)
		{
			write(handle->fd_write, &tmp, 1);
			tmp = 0;
		}
		i++;
	}
}

void			print_cor(t_asm *handle)
{
	char		zero;
	char		tmp;

	zero = 0;
	tmp = handle->size_magic;
	while (4 - tmp / 2)
	{
		write(handle->fd_write, &zero, 1);
		tmp += 2;
	}
	print_magic(handle);
	write(handle->fd_write, &handle->header.prog_name, sizeof(handle->header.prog_name));
	write(handle->fd_write, &handle->header.prog_size, sizeof(unsigned int));
	write(handle->fd_write, &handle->header.comment, sizeof(handle->header.comment));
}

void			print_hex_fd(t_asm *handle, unsigned int nb, int fd)
{
	if (nb >= 16)
		print_hex_fd(handle, nb / 16, fd);
	ft_putchar_fd(nb % 16, handle->fd_write);
}
