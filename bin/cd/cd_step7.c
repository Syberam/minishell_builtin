/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:41:13 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/28 05:54:20 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

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
