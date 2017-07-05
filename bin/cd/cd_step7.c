/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:41:13 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/29 00:01:44 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

char		cd_step7_opp(char *destpath, char **env, t_opt *options)
{
	char	*pwd;
	char	*oldpwd;
	char	*test_lsym;

	oldpwd = getcwd(oldpwd, 255);
	if (!(chdir(destpath) == -1))
		return (CD_CHDIR_FAILURE);
	oldpwd = ft_strcat("OLDPWD=", oldpwd);
	ft_setenv(oldpwd, env, 1);
	ft_setenv(destpath, env, 1);
	ft_bzero(destpath, ft_strlen(destpath));
	free(destpath);
	return (SUCCESS)
}

char	cd_step7(char *destpath, char **env, t_opt *options)
{
	char	*working_dir;

	if (options->p)
		return (cd_step10(destpath, env, options));
	working_dir = NULL;
	if (destpath[0] != '/')
		destpath = ft_ext_strjoin_free(getcwd(working_dir, 256),
							ft_strjoin("/", destpath), 2);
	return (cd_step8(destpath, env, options));
}
