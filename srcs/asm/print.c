/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:54:16 by akremer           #+#    #+#             */
/*   Updated: 2019/11/28 15:49:29 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_cor(t_asm *handle)
{
	//write(handle->fd_write, &handle->header.magic, sizeof(handle->header.magic));
	print_hex_fd(handle, handle->header.magic, handle->fd_write);
	write(handle->fd_write, &handle->header.prog_name, sizeof(handle->header.prog_name));
	write(handle->fd_write, &handle->header.comment, sizeof(handle->header.comment));
}

void			print_hex_fd(t_asm *handle, unsigned int nb, int fd)
{
	if (nb >= 16)
		print_hex_fd(handle, nb / 16, fd);
	ft_putchar_fd(nb % 16, handle->fd_write);
}
