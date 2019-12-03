/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:08:42 by akremer           #+#    #+#             */
/*   Updated: 2019/12/03 18:10:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_handle(t_asm *handle, char *av)
{
	header_t		header;

	header.prog_size = 0xffffffff;
	ft_bzero(header.prog_name, sizeof(header.prog_name));
	header.prog_name[0] = '\n';
	ft_bzero(header.comment, sizeof(header.comment));
	header.comment[0] = '\n';
	header.magic = COREWAR_EXEC_MAGIC;
	handle->header = header;
	handle->size_prog_size = ft_nbrlen((unsigned long long) handle->header.prog_size, 0, 16);
	handle->size_magic = ft_nbrlen((unsigned long long) handle->header.magic, 0, 16);
	handle->fd_read = 0;
	if (handle->size_magic / 2)
		handle->odd = 0;
	else
		handle->odd = 1;
	handle->bin = NULL;
	handle->fd_write = 0;
	handle->av = av;
	handle->op_tab = gopt();
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
	test_op(&handle);
	parsing(&handle);
	fill_handle(&handle);
	ft_printf("Tranquille ce soir !\n");
	// change label seg
	change_label(&handle);
	test_handle(&handle);
	test_inst(&handle);
	print_cor(&handle);
	close(handle.fd_read);
	close(handle.fd_write);
	return (0);
}
