/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 05:55:10 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/23 07:05:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

char	cd_step9(char *destpath)
{
	ft_putstr_fd("cd: path: ", 2);
	ft_putstr_fd(destpath, 2);
	ft_putendl_fd(" too long", 2);
	return (0);
}
