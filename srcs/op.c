/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/12/03 20:57:31 by akremer          ###   ########.fr       */
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

t_op    op_tab[17] =
{
	{ "live", 1,                                               {T_DIR},  1,   10,          "alive", 0, 0},
	{   "ld", 2,                                {T_DIR | T_IND, T_REG},  2,    5,           "load", 1, 0},
	{   "st", 2,                                {T_REG, T_IND | T_REG},  3,    5,          "store", 1, 0},
	{  "add", 3,                                 {T_REG, T_REG, T_REG},  4,   10,       "addition", 1, 0},
	{  "sub", 3,                                 {T_REG, T_REG, T_REG},  5,   10,   "soustraction", 1, 0},
	{  "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},  6,    6,            "and", 1, 0},
	{   "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},  7,    6,             "ou", 1, 0},
	{  "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},  8,    6,            "xor", 1, 0},
	{ "zjmp", 1,                                               {T_DIR},  9,   20,   "jump if zero", 0, 1},
	{  "ldi", 3,         {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10,   25,     "load index", 1, 1},
	{  "sti", 3,         {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11,   25,    "store index", 1, 1},
	{ "fork", 1,                                               {T_DIR}, 12,  800,           "fork", 0, 1},
	{  "lld", 2,                                {T_DIR | T_IND, T_REG}, 13,   10,      "long load", 1, 0},
	{ "lldi", 3,         {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14,   50,"long load index", 1, 1},
	{"lfork", 1,                                               {T_DIR}, 15, 1000,      "long fork", 0, 1},
	{  "aff", 1,                                               {T_REG}, 16,    2,            "aff", 1, 0},
	{      0, 0,                                                   {0},  0,    0,                0, 0, 0}
};
