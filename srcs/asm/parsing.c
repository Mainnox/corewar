/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:46:17 by akremer           #+#    #+#             */
/*   Updated: 2019/12/19 02:19:19 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		parse_name(t_asm *handle, char *buf)
{
	int				i;
	size_t			len_name;

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
	ft_strncpy(handle->header.prog_name, buf, len_name);
	i = len_name + 1;
	while (buf[i] == 't' || buf[i] == ' ')
		i++;
	if (buf[i] == '\0' || buf[i] == COMMENT_CHAR)
		return (0);
	return (1);
}

static int		parse_comment(t_asm *handle, char *buf)
{
	int			i;
	size_t		len_name;

	i = 0;
	while (buf[i] == '\t' || buf[i] == ' ')
		i++;
	if (ft_strncmp(COMMENT_CMD_STRING, buf + i, ft_strlen(COMMENT_CMD_STRING)) != 0)
		return (1);
	i += ft_strlen(COMMENT_CMD_STRING);
	while (buf[i] == '\t' || buf[i] == ' ')
		i++;
	if (buf[i] != '\"')
		return (1);
	buf += i + 1;
	len_name = ft_strclen(buf, '\"');
	if (len_name == ft_strlen(buf))
		return (1);
	ft_strncpy(handle->header.comment, buf, len_name);
	i = len_name + 1;
	while (buf[i] == 't' || buf[i] == ' ')
		i++;
	if (buf[i] == '\0' || buf[i] == COMMENT_CHAR)
		return (0);
	return (1);
}

int				parsing(t_asm *handle)
{
	char		*buf;

	while (get_next_line(handle->fd_read, &buf) > 0)
	{
		handle->count_line++;
		if (check_blanc(buf) && ft_strdel(&buf))
			continue ;
		if (handle->header.prog_name[0] == '\n')
		{
			if (parse_name(handle, buf) && ft_strdel(&buf))
				error_name(handle);
			ft_strdel(&buf);
			continue ;
		}
		if (handle->header.prog_name[0] != '\n' && handle->header.comment[0] == '\n')
		{
			if (parse_comment(handle, buf) && ft_strdel(&buf))
				error_comment(handle);
			ft_strdel(&buf);
			continue ;
		}
		if (handle->header.prog_name[0] != '\n' && handle->header.comment[0] != '\n')
			if (parse_instruc(handle, buf) && ft_strdel(&buf))
				error_instruc(handle, buf);
		ft_strdel(&buf);
	}
	return (1);
}
