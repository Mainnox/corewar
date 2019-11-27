/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 01:57:28 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/27 05:51:34 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int error_arg(t_env *env)
{
	(void)env;
	ft_putendl("Error");
	//free_env(env);
	return (0);
}

static int	ft_usage(void)
{
	ft_putendl("Usage: ./corewar <champion1.cor> <...>");
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (ft_usage());
	if (init_env(&env) == 0)
		return (error_arg(&env));
	if (parsing(av, &env) == 0)
		return (error_arg(&env));
	return (0);
}
