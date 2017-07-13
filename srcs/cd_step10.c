/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:05:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 16:12:58 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char			cd_step10(char *destpath, t_env *env, t_opt *options)
{
	char		*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 255);
	if ((chdir(destpath)) == -1)
	{
		ft_memdel((void **)&pwd);
		return (CD_CHDIR_FAILURE);
	}
	if (options->oldp)
		ft_putendl(destpath);
	pwd = ft_ext_strjoin_free("OLDPWD=", pwd, 2);
	ft_setenv(pwd, env, 0);
	destpath = ft_ext_strjoin_free("PWD=", destpath, 0);
	ft_setenv(destpath, env, 0);
	return (0);
}
