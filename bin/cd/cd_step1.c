/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:44:58 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/28 01:11:20 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

char	cd_step1(char *destpath)
{
	if (destpath && ft_strcmp(destpath, ""))
		return (cd_step2(destpath));
	return (CD_NOHOME);
}

char		cd_step2(char *destpath)
{
	t_stat	path_stat;

	if (lstat(destpath, &path_stat) == -1)
		return (CD_WGDIR);
	if ((path_stat.st_mode & S_IXUSR) != S_IXUSR)
		return (CD_PERMDEN);
	return (0);
}
/*
char		cd_step3(char *destpath)
{

}*/
