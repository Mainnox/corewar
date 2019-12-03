/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:45:45 by akremer           #+#    #+#             */
/*   Updated: 2019/12/03 01:58:09 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			check_name(t_asm *handle, char *buf, t_inst *new)
{
	int			j;
	int			i;

	i = 0;
	j = 0;
	while (ft_isalpha(buf[i]))
		i++;
	while (handle->op_tab[j].name)
	{
		if (ft_strncmp(handle->op_tab[j].name, buf, i) == 0
				&& ft_strlen(handle->op_tab[j].name) == (size_t)i)
		{
			new->name = ft_strndup(buf, i);
			new->opcode = handle->op_tab[j].opcode;
			new->nb_arg = handle->op_tab[j].nb_arg;
			return (i);
		}
		j++;
	}
	return (0);
}

static void			put_new_in_handle(t_asm *handle, t_inst *new)
{
	t_inst		*tmp;

	tmp = handle->inst;
	if (!tmp)
		handle->inst = new;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

static int			check_label(char *buf, t_inst *new)
{
	int			i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, buf[i]))
		i++;
	if (buf[i] == LABEL_CHAR)
	{
		new->label = ft_strndup(buf, i);
		return (i + 1);
	}
	return (0);
}

static void			put_arg_in_new(t_inst *new, t_arg *arg)
{
	t_arg		*tmp;

	tmp = new->arg;
	if (!tmp)
	{
		new->arg = arg;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = arg;
}

static void			add_arg(t_inst *new, char *buf, char code, int *j)
{
	t_arg		*arg;
	int			i;

	i = 0;
	if (!(arg = (t_arg*)ft_memalloc(sizeof(t_arg))))
		error_malloc();
	arg->type_arg = code;
	if (code == 4)
	{
		buf++;
		*j = *j + 1;
	}
	if (*buf == LABEL_CHAR)
	{
		buf++;
		*j = *j + 1;
		while (ft_strchr(LABEL_CHARS, buf[i]))
			i++;
		arg->label = ft_strndup(buf, i);
		*j = *j + i;
		put_arg_in_new(new, arg);
		return ;
	}
	if (code == 1)
	{
		buf++;
		*j = *j + 1;
		arg->valeur = ft_atoui(buf);
		if (arg->valeur == 0 || arg->valeur > REG_NUMBER)
			error_instruc();
	}
	if (code == 2 || code == 4)
	{
		arg->valeur = ft_atoui(buf);
		if (arg->valeur == 0)
		{
			if (*buf == '-' || *buf == '+')
				buf++;
			if (*buf < '0' || *buf > '9')
				error_instruc();
		}
	}
	put_arg_in_new(new, arg);
}

static void			check_arg(char *buf, t_inst *new, int *i)
{
	if (*buf == DIRECT_CHAR)
		add_arg(new, buf, 4, i);
	else if (*buf == LABEL_CHAR)
		add_arg(new, buf, 2, i);
	else if (*buf == 'r')
		add_arg(new, buf, 1, i);
	else if (*buf == '-' || *buf == '+' || (*buf >= '0' && *buf <= '9'))
		add_arg(new, buf, 2, i);
	else
		error_instruc();
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
		ft_printf("buf = %s\n", buf + i);
		while (ft_strchr(LABEL_CHARS, buf[i]))
			i++;
	ft_printf("i = %d\n", i);
		return (i);
	}
	while (buf[i] == '-' || buf[i] == '+' || (buf[i] >= '0' && buf[i] <= '9'))
		i++;
	return (i);
}

int					parse_instruc(t_asm *handle, char *buf)
{
	int		i;
	t_inst	*new;
	char	first;

	i = 0;
	first = 0;
	if (!(new = (t_inst*)ft_memalloc(sizeof(t_inst))))
		return (1);
	ft_bzero(new, sizeof(t_inst));
	while (ft_isblank(*buf))
		buf++;
	buf += check_label(buf, new);
	i = check_name(handle, buf, new);
	if (!i)
		error_instruc();
	buf += i;
	while (*buf || *buf == COMMENT_CHAR)
	{
		i = 0;
		ft_printf("buf1 = |%s|\n", buf);
		while (ft_isblank(*buf))
			buf++;
		ft_printf("buf1 = |%s|\n", buf);
		if (*buf == COMMENT_CHAR)
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
				error_instruc();
		}
		check_arg(buf, new, &i);
		ft_printf("buf1 = |%s|\n", buf);
		ft_printf("avance_buf = %d\n", avance_buf(buf));
		buf += avance_buf(buf);
		ft_printf("buf1 = |%s|\n", buf);
		first = 1;
	}
	put_new_in_handle(handle, new);
	test_inst(handle);
	return (0);
}
