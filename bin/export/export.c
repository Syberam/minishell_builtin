/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 04:48:25 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/24 05:26:37 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

/*
** options
		-l ??
	   	-p show the pointed var.
*/

int			main(int ac, char **av, char **env)
{
	size_t	i;
	if (ac == 1)
	{
		return (0);
	/*ft_print_sortenv(env);*/
	}
	env[0][6] = 0;
	ft_putendl(env[0]);
	return (0);
}
