/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 20:00:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 01:32:46 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

void	ft_cd_errors(char err_id, char *destpath, t_opt *options)
{
	if (err_id == CD_NOHOME)
		ft_putendl_fd("MiniShell: cd: HOME not set", 2);
	if (err_id == CD_NOTDIR)
		ft_putstr_fd("MiniShell: cd: not a directory: ", 2);
	if (err_id == CD_PERMDEN)
		ft_putstr_fd("MiniShell: cd: permission denied: ", 2);
	if (err_id == CD_WGDIR)
		ft_putstr_fd("MiniShell: cd: no such file or directory: ", 2);
	if (err_id == CD_CHDIR_FAILURE)
		ft_putstr_fd("MiniShell: cd: fail to go in: ", 2);
	if (err_id == CD_WGDIR || err_id == CD_PERMDEN
			|| err_id == CD_NOTDIR || err_id == CD_CHDIR_FAILURE)
	{
		ft_putendl_fd(destpath, 2);
		ft_memdel((void **)&destpath);
	}
	ft_memdel((void **)&options);
}
