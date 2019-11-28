/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:56:00 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/28 13:31:49 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define USAGE "Usage: ./asm champion.s"
# include "libft.h"
# include "op.h"

typedef struct 				s_asm
{
	int						fd_read;
	int						fd_write;
	char					*av;
	char					*bin;
	char					*name;
	char					*comment;
}							t_asm;

/*
**							test_functions
*/

void						test_handle(t_asm *handle);

/*
**							error_functions
*/

void						error_ac(void);
void						error_open(void);
void						error_name(void);
void						error_comment(void);
void						error_malloc(void);

/*
**							parsing_functions
*/

int							parsing(t_asm *handle);

/*
** 							print_functions
*/

void						print_hex_fd(long nb, int fd);

/*
**							open_functions
*/

void						open_bar(t_asm *handle);

#endif
