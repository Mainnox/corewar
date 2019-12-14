/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:01:35 by akremer           #+#    #+#             */
/*   Updated: 2019/12/14 01:51:15 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			open_bar(t_asm *handle)
{
	size_t		len_name_s;

	len_name_s = ft_strlen(handle->av);
	handle->fd_read = open(handle->av, O_RDONLY);
	if (handle->fd_read < 2)
		error_open();
	handle->bin = ft_strdup(handle->av);
	handle->bin[len_name_s - 1] = 'c';
	handle->bin[len_name_s] = 'o';
	handle->bin[len_name_s + 1] = 'r';
	handle->bin[len_name_s + 2] = '\0';
	handle->fd_write =  open(handle->bin, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	if (handle->fd_write == -1)
		error_open();
}
