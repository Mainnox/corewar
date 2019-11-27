/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:08:42 by akremer           #+#    #+#             */
/*   Updated: 2019/11/27 01:03:42 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static void		init_handle(t_asm *handle)
{
	handle->fd_read = 0;
	handle->name = NULL;
	handle->comment = NULL;
	handle->fd_write = 0;
}

int				main(int ac, char **av)
{
	t_asm		handle;
	int			error;

	if (ac != 2)
		error_ac();
	init_handle(&handle);
	handle.fd_read = open(av[1], O_RDONLY);
	if (handle.fd_read < 2)
		error_open();
	parsing(&handle);
	close(handle.fd_read);
	return (0);
}
