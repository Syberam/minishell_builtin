/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:15:17 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/07 07:51:52 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

static char	*ft_skip_extradotdot(char *destpath)
{
	size_t	i;
	char	state;
	char	*destpath_tmp;

	i = 0;
	while (destpath[i])
	{
		state = 0;
		if (i > 1 && destpath[i] == 46 && destpath[i + 1] == 46
				&& (destpath[i + 2] == 47 || destpath[i + 2] == 0)
				&& destpath[i - 1] == 47 && destpath[i - 2] != 46)
		{
			destpath_tmp = ft_strdup(destpath + i + 2);
			while (state != 2)
				state += (destpath[i--] == 47) ? 1 : 0;
			destpath_tmp = ft_ext_strjoin_free(ft_strsub(destpath, 0, i + 1),
								destpath_tmp, 2);
			ft_bzero(destpath, ft_strlen(destpath));
			free(destpath);
			destpath = destpath_tmp;
		}
		else
			i++;
	}
	return (destpath);
}

static char	*ft_skip_extraslashes(char *destpath)
{
	size_t	i;
	char	*destpath_tmp;

	i = 0;
	while (destpath[i])
	{
		if (destpath[i] == 47 && destpath[i + 1] == 47)
		{
			destpath_tmp =
	ft_ext_strjoin_free(ft_strsub(destpath, 0, i), destpath + i + 1, 1);
			ft_bzero(destpath, ft_strlen(destpath));
			free(destpath);
			destpath = destpath_tmp;
		}
		else
			i++;
	}
	return (destpath);
}

static char	*ft_skip_dot(char *destpath)
{
	size_t	i;
	char	*destpath_tmp;

	i = 0;
	while (destpath[i])
	{
		if ((i == 0 && destpath[i] == 46 && destpath[i + 1] == 47) || ((i > 0
	&& destpath[i - 1] != 46) && destpath[i] == 46 && destpath[i + 1] == 47))
		{
			destpath_tmp =
	ft_ext_strjoin_free(ft_strsub(destpath, 0, i - 1), destpath + i + 1, 1);
			ft_bzero(destpath, ft_strlen(destpath));
			free(destpath);
			destpath = destpath_tmp;
		}
		else
			i++;
	}
	return (destpath);
}

char		cd_step8(char *destpath, t_env *env, t_opt *options)
{
	destpath = ft_skip_dot(destpath);
	destpath = ft_skip_extraslashes(destpath);
	destpath = ft_skip_extradotdot(destpath);
	if (ft_strlen(destpath) > 255)
		return (cd_step9(destpath));
	return (cd_step10(destpath, env, options));
}
