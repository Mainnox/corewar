/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:56:00 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/12/03 00:29:54 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define USAGE "Usage: ./asm champion.s"
# include "libft.h"
# include "op.h"

typedef struct				s_arg
{
	char					type_arg;
	unsigned int			valeur;
	char					*label;
	struct s_arg			*next;
}							t_arg;

typedef struct				s_inst
{
	char					opcode;
	char					nb_arg;
	char					*label;
	char					*name;
	t_arg					*arg;
	struct s_inst			*next;
}							t_inst;

typedef struct 				s_asm
{
	char					odd;
	char					size_magic;
	char					size_prog_size;
	int						fd_read;
	int						fd_write;
	char					*av;
	char					*bin;
	t_inst					*inst;
	t_op					*op_tab;
	header_t				header;
}							t_asm;

/*
**							test_functions
*/

void						test_handle(t_asm *handle);
void						test_inst(t_asm *handle);
void						test_op(t_asm *handle);

/*
**							error_functions
*/

void						error_ac(void);
void						error_open(void);
void						error_name(void);
void						error_comment(void);
void						error_malloc(void);
void						error_instruc(void);

/*
**							check_functions
*/

int							check_blanc(char *buf);

/*
**							parsing_functions
*/

int							parsing(t_asm *handle);
int							parse_instruc(t_asm *handle, char *buf);

/*
** 							print_functions
*/

void						print_cor(t_asm *handle);
void						print_hex_fd(t_asm *handle, unsigned int nb, char size, char odd);

/*
**							open_functions
*/

void						open_bar(t_asm *handle);

/*
**							global_functions
*/

t_op						*gopt(void);

#endif
