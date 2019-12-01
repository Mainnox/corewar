/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:08:42 by akremer           #+#    #+#             */
/*   Updated: 2019/12/01 23:40:16 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_handle(t_asm *handle, char *av)
{
	header_t		header;

	header.prog_size = 20;
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
	t_op    op_tab[17] =
	{
		{ "live", 1,                                               {T_DIR},  1,   10,          "alive", 0, 0},
		{   "ld", 2,                                {T_DIR | T_IND, T_REG},  2,    5,           "load", 1, 0},
		{   "st", 2,                                {T_REG, T_IND | T_REG},  3,    5,          "store", 1, 0},
		{  "add", 3,                                 {T_REG, T_REG, T_REG},  4,   10,       "addition", 1, 0},
		{  "sub", 3,                                 {T_REG, T_REG, T_REG},  5,   10,   "soustraction", 1, 0},
		{  "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},  6,    6,            "and", 1, 0},
		{   "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},  7,    6,             "ou", 1, 0},
		{  "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},  8,    6,            "xor", 1, 0},
		{ "zjmp", 1,                                               {T_DIR},  9,   20,   "jump if zero", 0, 1},
		{  "ldi", 3,         {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10,   25,     "load index", 1, 1},
		{  "sti", 3,         {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11,   25,    "store index", 1, 1},
		{ "fork", 1,                                               {T_DIR}, 12,  800,           "fork", 0, 1},
		{  "lld", 2,                                {T_DIR | T_IND, T_REG}, 13,   10,      "long load", 1, 0},
		{ "lldi", 3,         {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14,   50,"long load index", 1, 1},
		{"lfork", 1,                                               {T_DIR}, 15, 1000,      "long fork", 0, 1},
		{  "aff", 1,                                               {T_REG}, 16,    2,            "aff", 1, 0},
		{      0, 0,                                                   {0},  0,    0,                0, 0, 0}
	};
	handle->op_tab = op_tab;
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
	print_cor(&handle);
	close(handle.fd_read);
	close(handle.fd_write);
	return (0);
}
