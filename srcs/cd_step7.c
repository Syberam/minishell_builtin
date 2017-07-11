/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:41:13 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 05:25:53 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char		cd_step7_opp(char *destpath, t_env *env)
{
	char	*oldpwd;

	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, 255);
	if (!(chdir(destpath) == -1))
		return (CD_CHDIR_FAILURE);
	oldpwd = ft_strcat("OLDPWD=", oldpwd);
	ft_setenv(oldpwd, env, 1);
	ft_setenv(destpath, env, 1);
	ft_bzero(destpath, ft_strlen(destpath));
	free(destpath);
	return (CD_SUCCESS);
}

char		cd_step7(char *destpath, t_env *env, t_opt *options)
{
	char	*working_dir;

	working_dir = NULL;
	if (destpath[0] != '/')
		destpath = ft_ext_strjoin_free(getcwd(working_dir, 256),
							ft_ext_strjoin_free("/", destpath, 2), 2);
	return (cd_step8(destpath, env, options));
}
