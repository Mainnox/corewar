/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:47:47 by akremer           #+#    #+#             */
/*   Updated: 2019/11/28 13:31:51 by akremer          ###   ########.fr       */
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
	ft_printf("| handle->name    =      %35s                     |\n", handle->name);
	ft_printf("| handle->comment =      %35s                     |\n", handle->comment);
	ft_printf("| handle->av      =      %35s                     |\n", handle->av);
	ft_printf("| handle->bin     =      %35s                     |\n", handle->bin);
	ft_printf("*================================================================================*\n");
}
