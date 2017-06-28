/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:41:13 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/23 07:16:09 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

char	cd_step7(char *destpath, char **env, t_opt options)
{
	char	*working_dir;

	if (options.p)
		return (cd_step10(destpath, env, options));
	working_dir = NULL;
	if (destpath[0] != '/')
		destpath = ft_ext_strjoin_free(getcwd(working_dir, 256),
							ft_strjoin("/", destpath), 2);
	ft_putstr("step 7 : ");
	ft_putstr("\t destpath : ");
	ft_putendl(destpath);
	return (cd_step8(destpath, env, options));
}
