/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:56:00 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/12/23 05:29:38 by akremer          ###   ########.fr       */
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
	unsigned char			ocp;
	int						size;
	char					*label;
	char					*name;
	t_arg					*arg;
	struct s_inst			*next;
}							t_inst;

typedef struct				s_helper
{
	char					*buf;
	t_inst					*new;
	int						j;
}							t_helper;

typedef struct 				s_asm
{
	char					odd;
	char					size_magic;
	char					size_prog_size;
	char					zero;
	char					code;
	int						count_line;
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

void						error_ac(t_asm *handle);
void						error_open(t_asm *handle);
void						error_name(t_asm *handle);
void						error_comment(t_asm *handle);
void						error_malloc(t_asm *handle);
void						error_instruc(t_asm *handle, char *buf);
void						error_no_inst(t_asm *handle);
void						error_too_much_arg(t_asm *handle, int nb_inst);
void						error_wrong_arg(t_asm *handle, char nb_arg, int nb_inst);
void						error_too_few_arg(t_asm *handle, int i);

/*
**							check_functions
*/

int							check_blanc(char *buf);
void						check_parsing(t_asm *handle);
void						check_rdi_rd_r(t_asm *handle, t_inst *inst, int i);
void						check_r_rdi_dr(t_asm *handle, t_inst *inst, int i);
void						check_r_r_r(t_asm *handle, t_inst *inst, int i);
void						check_d(t_asm *handle, t_inst *inst, int i);
void						check_di_r(t_asm *handle, t_inst *inst, int i);
void						check_r_ir(t_asm *handle, t_inst *inst, int i);
void						check_rdi_rdi_r(t_asm *handle, t_inst *inst, int i);

/*
**							parsing_functions
*/

int							parsing(t_asm *handle);
int							parse_instruc(t_asm *handle, char *buf);
void						add_arg_helper_3(char *buf, t_arg *arg, int *j, int i);
void						add_arg_helper_2(t_asm *handle, char *buf, t_arg *arg, int *j);
void						add_arg_helper_1(t_asm *handle, t_inst *new, char *buf, t_arg *arg);
void						put_arg_in_new(t_inst *new, t_arg *arg);
int							check_label(char *buf, t_inst *new);
int							check_name(t_asm *handle, char *buf, t_inst *new);
void						put_new_in_handle(t_asm *handle, t_inst *new);

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
**							change_fonctions
*/

void						change_label(t_asm *handle);

/*
**							global_functions
*/

t_op						*gopt(void);

/*
** 							fill_functions
*/

void						fill_handle(t_asm *handle);
void						fill_ocp_0(t_inst *inst, t_arg *arg);
void						fill_ocp_1(t_inst *inst, t_arg *arg);
void						fill_ocp_2(t_inst *inst, t_arg *arg);

/*
**							free_functions
*/

void						free_all(t_asm *handle);

/*
** 							swap_functions
*/

void						swap_int(unsigned int *it);
void						swap_short(unsigned short *it);

#endif
