/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:16 by akremer           #+#    #+#             */
/*   Updated: 2019/12/04 00:09:50 by akremer          ###   ########.fr       */
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
		nb /= 16;
	}
	ft_strrev(tab);
	i = 0;
	if (odd)
		write(handle->fd_write, &tab[i++], 1);
	while (tab[i])
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

void			print_cor(t_asm *handle)
{
	char		zero;
	char		tmp;
	char		i;

	i = 0;
	zero = 0;
	tmp = handle->size_magic;
	while (4 - tmp / 2)
	{
		write(handle->fd_write, &zero, 1);
		tmp += 2;
	}
	print_hex_fd(handle, handle->header.magic, handle->size_magic, handle->odd);
	write(handle->fd_write, &handle->header.prog_name, sizeof(handle->header.prog_name));
	while (++i < 4)
		write(handle->fd_write, &zero, sizeof(char));
	print_hex_fd(handle, handle->header.prog_size, handle->size_prog_size, (handle->size_prog_size / 2) ? 0 : 1);
	write(handle->fd_write, &handle->header.comment, sizeof(handle->header.comment));
	while (++i < 11)
		write(handle->fd_write, &zero, sizeof(char));
}

