/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:08:42 by akremer           #+#    #+#             */
/*   Updated: 2019/11/28 13:31:52 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_handle(t_asm *handle, char *av)
{
	handle->fd_read = 0;
	handle->name = NULL;
	handle->comment = NULL;
	handle->bin = NULL;
	handle->fd_write = 0;
	handle->av = av;
}

int				main(int ac, char **av)
{
	t_asm		handle;

	if (ac != 2)
		error_ac();
	init_handle(&handle, av[1]);
	open_bar(&handle);
	handle.fd_read = open(av[1], O_RDONLY);
	if (handle.fd_read < 2)
		error_open();
	parsing(&handle);
	test_handle(&handle);
	close(handle.fd_read);
	return (0);
}
