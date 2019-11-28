/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:01:35 by akremer           #+#    #+#             */
/*   Updated: 2019/11/28 13:31:46 by akremer          ###   ########.fr       */
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
	if (!(handle->bin = (char*)ft_memalloc(sizeof(char) * len_name_s + 3)))
		error_malloc();
	handle->bin = ft_strdup(handle->av);
	handle->bin[len_name_s - 1] = 'c';
	handle->bin[len_name_s] = 'o';
	handle->bin[len_name_s + 1] = 'r';
	handle->bin[len_name_s + 2] = '\0';
	handle->fd_write = open(handle->bin, O_WRONLY | O_CREAT, 0644);
	if (handle->fd_write == -1)
		error_open();
}
