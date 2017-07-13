/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 05:36:00 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 16:04:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char	cd_step6(char *destpath, t_env *env, t_opt *options)
{
	char	*pwd;
	size_t	len_cur;
	size_t	len_dad;

	pwd = NULL;
	if (!ft_strcmp(destpath, ".\0") || !ft_strcmp(destpath, "\0"))
	{
	//	ft_memdel((void **)&destpath);
		destpath = getcwd(destpath, 255);
	}
	else if (!ft_strcmp(destpath, "..\0"))
	{
		pwd = getcwd(pwd, 255);
		len_cur = ft_strlen(ft_strrchr(pwd, '/'));
		len_dad = ft_strlen(pwd) - len_cur;
		ft_memdel((void **)&destpath);
		destpath = ft_strsub(pwd, 0, len_dad);
		ft_memdel((void **)&pwd);
	}
	return (cd_step7(destpath, env, options));
}
