/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 20:00:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 04:15:28 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

int		ft_cd_errors(char err_id, char *destpath)
{
	if (err_id == CD_NOHOME)
		return (0);
	if (err_id == CD_PERMDEN)
		ft_putstr_fd("cd: permission denied: ", 2);
	if (err_id == CD_WGDIR)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	if (err_id == CD_CHDIR_FAILURE)
		ft_putstr_fd("cd: fail to go in: ", 2);
	if (err_id == CD_WGDIR || err_id == CD_PERMDEN
											|| err_id == CD_CHDIR_FAILURE)
		ft_putendl_fd(destpath, 2);
	return (0);
}