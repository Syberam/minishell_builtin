/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 00:23:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/23 00:29:58 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish_errors.h"

int		main(int ac, char **av)
{
	if (!ac)
		return (0);
	ft_putstr_fd("MiniShell: Command not found: ", 2);
	ft_putendl_fd(av[0], 2);
	return (0);
}
