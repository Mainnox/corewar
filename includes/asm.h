/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:56:00 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/28 19:48:19 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define USAGE "Usage: ./asm champion.s"
# include "libft.h"
# include "op.h"

typedef struct 				s_asm
{
	char					odd;
	char					size_magic;
	char					size_prog_size;
	int						fd_read;
	int						fd_write;
	char					*av;
	char					*bin;
	header_t				header;
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

void						print_cor(t_asm *handle);
void						print_hex_fd(t_asm *handle, unsigned int nb, char size, char odd);

/*
**							open_functions
*/

void						open_bar(t_asm *handle);

#endif
