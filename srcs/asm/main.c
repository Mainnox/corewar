/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:08:42 by akremer           #+#    #+#             */
/*   Updated: 2019/12/23 05:20:58 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_handle(t_asm *handle, char *av)
{
	header_t		header;

	header.prog_size = 0;
	ft_bzero(header.prog_name, sizeof(header.prog_name));
	header.prog_name[0] = '\n';
	ft_bzero(header.comment, sizeof(header.comment));
	header.comment[0] = '\n';
	header.magic = COREWAR_EXEC_MAGIC;
	handle->header = header;
	handle->size_prog_size = ft_nbrlen(
			(unsigned long long)handle->header.prog_size, 0, 16);
	handle->size_magic = ft_nbrlen(
			(unsigned long long)handle->header.magic, 0, 16);
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

static void		all_good(t_asm *handle)
{
	char		*name;
	char		*tmp;
	size_t		len;

	len = ft_strlen(handle->av) - 1;
	name = ft_strdup(handle->av);
	name[len - 1] = '\0';
	tmp = name;
	while (len && name[len] != '/')
		len--;
	name += len + 1;
	ft_printf("LADIES AND GENTLEMANS !\n");
	ft_printf("ARE YOU READY FOR OUR NEW CHALLENGER : %s !\n", name);
	ft_printf("WAITING FOR A BLOODY FIGHT AT HIM NEW PLACE ");
	ft_printf("I NAMED : %s\n", handle->bin);
	free(tmp);
}

int				main(int ac, char **av)
{
	t_asm		handle;

	(void)av;
	if (ac != 2)
		error_ac(&handle);
	init_handle(&handle, av[1]);
	open_bar(&handle);
	handle.fd_read = open(av[1], O_RDONLY);
	if (handle.fd_read < 2)
		error_open(&handle);
	parsing(&handle);
	check_parsing(&handle);
	fill_handle(&handle);
	change_label(&handle);
	print_cor(&handle);
	all_good(&handle);
	free_all(&handle);
	return (0);
}
