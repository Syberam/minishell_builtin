/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 01:52:18 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 11:16:39 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

static char		*ft_get_tmpdest(char *destpath, char **cdpaths)
{
	char		*tmp_dest;
	char		i;
	t_stat		dir_stat;

	i = 0;
	while (cdpaths[++i - 1])
	{
		if (ft_strcmp(cdpaths[i - 1], ""))
			tmp_dest = (cdpaths[i - 1][ft_strlen(cdpaths[i - 1])] == '/') ?
		ft_ext_strjoin_free(cdpaths[i - 1], destpath, 2) :
	ft_ext_strjoin_free(ft_strjoin(cdpaths[i - 1], "/"), destpath, 3);
		else if (i - 1 == 0)
			tmp_dest = ft_strjoin("./", destpath);
		else
			continue;
		if ((lstat(tmp_dest, &dir_stat)) && S_ISDIR(dir_stat.st_mode))
			break ;
		ft_bzero(tmp_dest, ft_strlen(tmp_dest));
		ft_memdel((void **)&tmp_dest);
		tmp_dest = NULL;
	}
	return (tmp_dest);
}

static char		**ft_get_cdpaths(t_env *env)
{
	char		*path_var;
	char		**cdpaths;

	path_var = ft_getenv_var("CDPATH", env);
	if (!path_var)
		return (NULL);
	cdpaths = ft_strsplit(path_var, ':');
	return (cdpaths);
}

char			cd_step5(char *destpath, t_env *env, t_opt *options)
{
	char		**cdpaths;
	char		*tmp_dest;
	int			i;

	if (!(cdpaths = ft_get_cdpaths(env)))
		return (cd_step7(destpath, env, options));
	if (!(tmp_dest = ft_get_tmpdest(destpath, cdpaths)))
		return (cd_step7(destpath, env, options));
	i = 0;
	ft_bzero(destpath, ft_strlen(destpath));
	ft_memdel((void **)&destpath);
	ft_freetab(cdpaths);
	destpath = tmp_dest;
	return (cd_step7(destpath, env, options));
}
