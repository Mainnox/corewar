/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/12/14 06:14:41 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

/*
**	1st parametter = instruction_format
**	2nd parametter = nb_parametre(s)
**	3rd parametter = type_parametre(s)
**	4th parametter = opcode_correspondant_alain_struction
**	5th parametter = nb_cycle_avant_exec
**	6th parametter = instruction_french_name
**	7th parametter = 
**	8th parametter = 
*/

static t_op    g_op_tab[17] =
{
	{  "sti", 3,         {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11,   25,    "store index", 1, 1},
	{  "aff", 1,                                               {T_REG}, 16,    2,            "aff", 1, 0},
	{      0, 0,                                                   {0},  0,    0,                0, 0, 0}
};

t_op			*gopt(void)
{
	return (g_op_tab);
}
