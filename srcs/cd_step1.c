/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:44:58 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 05:23:05 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char		*ft_fill_destpath(char *destpath, t_env *env)
{
	if (destpath || ft_strcmp(destpath, ""))
		return (destpath);
	return (ft_getenv_var("HOME", env));
}

char		cd_step1(char *destpath, t_env *env, t_opt *options)
{
	if (destpath && ft_strcmp(destpath, ""))
		return (cd_step2(destpath, env, options));
	return (CD_NOHOME);
}

char		cd_step2(char *destpath, t_env *env, t_opt *options)
{
	t_stat	path_stat;

	if ((lstat(destpath, &path_stat)) == -1)
		return (CD_WGDIR);
	if (S_ISBLK(path_stat.st_mode) || S_ISCHR(path_stat.st_mode) ||
			S_ISSOCK(path_stat.st_mode) || S_ISFIFO(path_stat.st_mode) ||
				S_ISREG(path_stat.st_mode))
		return (CD_NOTDIR);
	if ((path_stat.st_mode & S_IXUSR) != S_IXUSR)
		return (CD_PERMDEN);
	return (cd_step3(destpath, env, options));
}

char		cd_step3(char *destpath, t_env *env, t_opt *options)
{
	if (destpath[0] == '/')
		return (cd_step7(destpath, env, options));
	else
		return (cd_step4(destpath, env, options));
}

char		cd_step4(char *destpath, t_env *env, t_opt *options)
{
	if (!ft_strcmp(destpath, ".\0") || !ft_strcmp(destpath, "..\0")
			|| !ft_strcmp(destpath, "\0"))
		return (cd_step6(destpath, env, options));
	return (cd_step5(destpath, env, options));
}
