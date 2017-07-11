/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 00:23:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 05:28:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish_errors.h"

void		error_wgcmd(char *av)
{
	ft_putstr_fd("MiniShell: Command not found: ", 2);
	ft_putendl_fd(av, 2);
	exit(0);
}
