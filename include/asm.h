/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:11:54 by akremer           #+#    #+#             */
/*   Updated: 2019/11/27 04:12:13 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define NAME_CMD_STRING	".name"
# define USAGE				"usage: ./asm champion.s"
# define COMMENT_CHAR 		'#'
# define COMMENT_CMD_STRING	".comment"

# include "../libft/includes/libft.h"

typedef struct					s_asm
{
	int			fd_read;
	int			fd_write;
	char		*name;
	char		*comment;
}								t_asm;

/*
**			Error_functions
*/

void							error_ac(void);
void							error_open(void);
void							error_name(void);
void							error_comment(void);

/*
**			Parsing_functions
*/

int							parsing(t_asm *handle);

/*
**			Test_functions
*/

void							test_handle(t_asm *handle);

#endif
