/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:35:18 by akremer           #+#    #+#             */
/*   Updated: 2020/02/01 15:41:12 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error_label(t_asm *handle, char *buf)
{
	ft_printf("Error label name here : %s\nPick a good name for this one", buf);
	ft_printf(" ,like Rouge seems to be a good name for a label.\n");
	free_all(handle);
	exit(0);
}
