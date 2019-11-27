/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:57:28 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/27 04:16:06 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_usage(void)
{
	ft_putendl("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>");
	ft_putendl("    -a        : Prints output from "aff" (Default is to hide it)");
	ft_putendl("#### TEXT OUTPUT MODE #######################################");
	ft_putendl("    -d N      : Dumps memory after N cycles then exits");
	ft_putendl("    -s N      : Runs N cycles, dumps memory, pauses, then repeats");
	ft_putendl("   -v N      : Verbosity levels, can be added together to enable several");
	ft_putendl("                - 0 : Show only essentials");
	ft_putendl("                - 1 : Show lives");
	ft_putendl("                - 2 : Show cycles");
	ft_putendl("                - 4 : Show operations (Params are NOT litteral)");
	ft_putendl("                - 8 : Show deaths");
	ft_putendl("                - 16 : Show PC movements (Except for jumps)");
	ft_putendl("#### BINARY OUTPUT MODE #####################################");
	ft_putendl("    -b        : Binary output mode for corewar.42.fr");
	ft_putendl("    --stealth : Hides the real contents of the memory");
	ft_putendl("#### NCURSES OUTPUT MODE ####################################");
	ft_putendl("    -n        : Ncurses output mode");
	ft_putendl("    --stealth : Hides the real contents of the memory");
	ft_putendl("#############################################################");
	return (0);
}

int			main(int ac, char **av)
{
	if (ac < 2)
		return (ft_usage());
	return (0);
}
