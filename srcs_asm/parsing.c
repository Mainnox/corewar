/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:46:17 by akremer           #+#    #+#             */
/*   Updated: 2019/11/27 02:15:39 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int		parse_name(t_asm *handle, char *buf)
{
	int			i;
	int			len_name;

	i = 0;
	while (buf[i] == '\t' || buf[i] == ' ')
		i++;
	if (ft_strncmp(NAME_CMD_STRING, buf + i, ft_strlen(NAME_CMD_STRING)) != 0)
		return (1);
	i += ft_strlen(NAME_CMD_STRING);
	while (buf[i] == '\t' || buf[i] == ' ')
		i++;
	if (buf[i] != '\"')
		return (1);
	buf += i + 1;
	len_name = ft_strclen(buf, '\"');
	if (len_name == ft_strlen(buf))
		return (1);
	handle->name = ft_strndup(buf, len_name);
	i = len_name + 1;
	while (buf[i] == 't' || buf[i] == ' ')
		i++;
	if (buf[i] == '\0' || buf[i] == COMMENT_CHAR)
	{
		free(handle->name);
		return (0);
	}
	return (1);
}

int				parsing(t_asm *handle)
{
	char		*buf;

	while (get_next_line(handle->fd_read, &buf) > 0)
	{
		if (buf[0] == '\0' && ft_strdel(&buf))
			continue;
		if (handle->name == NULL)
			if (parse_name(handle, buf) && ft_strdel(&buf))
				error_name();
		free(buf);
	}
	return (1);
}
