/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 05:36:00 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 04:27:14 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

char	cd_step6(char *destpath, char **env, t_opt *options)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 255);
	pwd = ft_strjoin(pwd, "/\0");
	destpath = ft_ext_strjoin_free(pwd, destpath, 2);
	return (cd_step7(destpath, env, options));
}
