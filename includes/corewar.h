/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:11:40 by lyhamrou          #+#    #+#             */
/*   Updated: 2019/11/27 05:47:31 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"

typedef struct		s_env
{
	int				nb_p;//nombre de joueurs
	unsigned char	map[MEM_SIZE];//arena
}					t_env;

int					init_env(t_env*env);
int					parsing(char **av, t_env *env);

#endif
