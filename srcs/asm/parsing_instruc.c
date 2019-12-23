/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:45:45 by akremer           #+#    #+#             */
/*   Updated: 2019/12/23 05:29:16 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			add_arg(t_asm *handle, t_inst *new,
		char *buf, int *j)
{
	t_arg		*arg;
	int			i;

	i = 0;
	if (!(arg = (t_arg*)ft_memalloc(sizeof(t_arg))))
		error_malloc(handle);
	ft_bzero(arg, sizeof(t_arg));
	arg->type_arg = handle->code;
	if (handle->code == 4)
	{
		buf++;
		*j = *j + 1;
	}
	if (*buf == LABEL_CHAR)
	{
		add_arg_helper_3(buf, arg, j, i);
		put_arg_in_new(new, arg);
		return ;
	}
	if (handle->code == 1)
		add_arg_helper_2(handle, buf, arg, j);
	if (handle->code == 2 || handle->code == 4)
		add_arg_helper_1(handle, new, buf, arg);
	put_arg_in_new(new, arg);
}

static void			check_arg(t_asm *handle, char *buf, t_inst *new, int *i)
{
	if (*buf == DIRECT_CHAR)
	{
		handle->code = 4;
		add_arg(handle, new, buf, i);
	}
	else if (*buf == LABEL_CHAR)
	{
		handle->code = 2;
		add_arg(handle, new, buf, i);
	}
	else if (*buf == 'r')
	{
		handle->code = 1;
		add_arg(handle, new, buf, i);
	}
	else if (*buf == '-' || *buf == '+' || (*buf >= '0' && *buf <= '9'))
	{
		handle->code = 2;
		add_arg(handle, new, buf, i);
	}
	else
		error_instruc(handle, buf);
}

static int			avance_buf(char *buf)
{
	int				i;

	i = 0;
	if (buf[i] == DIRECT_CHAR || buf[i] == 'r')
		i++;
	if (buf[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, buf[i]))
			i++;
		return (i);
	}
	while (buf[i] == '-' || buf[i] == '+' || (buf[i] >= '0' && buf[i] <= '9'))
		i++;
	return (i);
}

static void			parse_inst_helper(t_asm *handle, char *buf,
		t_inst *new, char first)
{
	int			i;

	i = 0;
	while (*buf || *buf == COMMENT_CHAR)
	{
		i = 0;
		while (ft_isblank(*buf))
			buf++;
		if (*buf == COMMENT_CHAR || !*buf)
			break ;
		if (first)
		{
			if (*buf == SEPARATOR_CHAR)
			{
				buf++;
				first = 0;
				continue ;
			}
			else
				error_instruc(handle, buf);
		}
		check_arg(handle, buf, new, &i);
		buf += avance_buf(buf);
		first = 1;
	}
}

int					parse_instruc(t_asm *handle, char *buf)
{
	int		i;
	t_inst	*new;
	char	first;

	i = 0;
	first = 0;
	if (!(new = (t_inst*)ft_memalloc(sizeof(t_inst))))
		error_malloc(handle);
	ft_bzero(new, sizeof(t_inst));
	while (ft_isblank(*buf))
		buf++;
	buf += check_label(buf, new);
	while (ft_isblank(*buf))
		buf++;
	i = check_name(handle, buf, new);
	if (!i)
		error_instruc(handle, buf);
	buf += i;
	parse_inst_helper(handle, buf, new, first);
	put_new_in_handle(handle, new);
	return (0);
}
