/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:45:45 by akremer           #+#    #+#             */
/*   Updated: 2019/12/02 00:10:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					parse_instruc(t_asm *handle, char *buf)
{
	int		i;
	t_inst	*new;

	i = 0;
	if (!(new = (t_inst*)ft_memalloc(sizeof(t_inst))))
		return (1);
	ft_bzero(new, sizeof(t_inst));
	while (ft_isblank(*buf))
		buf++;
	while (ft_strchr(LABEL_CHARS, buf[i]) != NULL)
		i++;
	if (buf[i] == LABEL_CHAR)
	{
		new->label = ft_strndup(buf, i);
		buf += i + 1;
		while (ft_isblank(*buf))
			buf++;
	}
	i = 0;
	while (ft_isalpha(buf[i]))
		i++;
	ft_printf("buf_act = %s\n", buf + i);
	if (handle)
		ft_printf("buf = %s\n", buf);
	return (0);
}
